#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BYTES_PER_BLOCK 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "%s\n", "Usage: magic infile");
        return 1;
    }
    
    //remember filename
    char *infile = argv[1];
    
    //open file
    FILE *in = fopen(infile, "r");
    
    //return error if file can't be opened
    if (in == NULL)
    {
        fprintf(stderr, "%s %s\n", "Could not open", infile);
        return 2;
    }
    
    //initialize buffer array to hold one block at a time
    uint8_t buffer[BYTES_PER_BLOCK];
    
    FILE *img;
    
    
    //read in one chunk of the input file
    fread(&buffer, BYTES_PER_BLOCK, 1, in);

    //check if JPEG
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 
        (buffer[3] & 0xf0) == 0xe0)
    {
        printf("JPEG\n");
    }
    
    //check if BMP
    else if (buffer[0] == 0x42 && buffer[1] == 0x4d)
    {
        printf("BMP\n");
    }
    
    //check if PDF
    else if (buffer[0] == 0x25 && buffer[1] && buffer[2] == 0x50 && 
             buffer[4] == 0x44 && buffer[5] == 0x46)
        printf("PDF\n");
        
    else 
    {
        printf("\n");
    }
    fclose(in); 
    return 0; 
}