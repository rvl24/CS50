#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#define BITS_PER_BYTE 8

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: resize f infile outfile\n");
        return 1;
    }
     
    float scale_factor = atof(argv[1]);
    if (scale_factor > 100 || scale_factor < 0)
    {
        printf("Scale factor must be 0 < f <= 100\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    FILE *in = fopen(infile, "r");
    if (in == NULL)
    {
        printf("Could not open infile\n");
        return 1;
    }
    
    FILE *out = fopen(outfile, "w");
    if (out == NULL)
    {
        fclose(in);
        printf("Could not write to outfile\n");
        return 1;
    }  

    BITMAPFILEHEADER bf_in; 
    fread(&bf_in, sizeof(BITMAPFILEHEADER), 1, in); 
    
    BITMAPINFOHEADER bi_in;
    fread(&bi_in, sizeof(BITMAPINFOHEADER), 1, in);
    
    //determine whether infile is a bitmap
    if (bf_in.bfType != 0x4d42 || bf_in.bfOffBits != 54 || bi_in.biSize != 40 ||
        bi_in.biBitCount != 24 || bi_in.biCompression != 0)
    {
        fclose(in);
        fclose(out);
        printf("Unsupported file format\n");
        return 1;
    }

    BITMAPFILEHEADER bf_out = bf_in;
    BITMAPINFOHEADER bi_out = bi_in;
    //get infile padding
    int in_padding = (4 - (bi_in.biWidth * sizeof(RGBTRIPLE) % 4)) % 4;  
    
    //update values that change in outfile's header
    bi_out.biWidth *= scale_factor;
   
    //get outfile padding
    int out_padding = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE) % 4)) % 4; 
    
    bi_out.biHeight *= scale_factor;
    bi_out.biSizeImage = abs(bi_out.biHeight) * (bi_out.biWidth * sizeof(RGBTRIPLE) + out_padding);  
    bf_out.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi_out.biSizeImage;
    
    //write outfile headers
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, out);
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, out); 
    
    //iterate over infile scanlines
    for (int i = 0, biHeight = abs(bi_in.biHeight); i < biHeight; i++)
    {
        //write each outfile scanline scale_factor times
        for (int j = 0; j < scale_factor; j++)
        {
            // iterate over pixels in infile scanline
            for (int k = 0; k < bi_in.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                fread(&triple, sizeof(RGBTRIPLE), 1, in);
                
                for (int l = 0; l < scale_factor; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, out);
                }
            }
            //add padding to end of outfile scanline
            for (int k = 0; k < out_padding; k++)  
            {
                fputc(0x00, out);
            }             
            //go back to beginning of infile scanline
            fseek(in, -bi_in.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);      

        }
        // go to next scanline, skipping over padding
        fseek(in, bi_in.biWidth * sizeof(RGBTRIPLE) + in_padding, SEEK_CUR);
    }
    
    fclose(in);
    fclose(out);
    return 0;
}