#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BYTES_PER_BLOCK 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "%s\n", "Usage: recover infile");
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
    
    //initialize buffer array to hold one block at a time. 
    uint8_t buffer[BYTES_PER_BLOCK];
    
    //initialize array to hold filenames
    char out_name[8];  
    
    int counter = -1; 
    
    FILE *img;
    
    while (fread(&buffer, BYTES_PER_BLOCK, 1, in) == 1)
    {
        //check start of block to see if JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 
           (buffer[3] & 0xf0) == 0xe0)
        {
            counter++;
            sprintf(out_name, "%03i.jpg", counter); 
            img = fopen(out_name, "w");
        }
        
        //In case infile does not start with a JPEG header
        if (counter >= 0)
        {
            //write from buffer to current JPEG
            fwrite(buffer, BYTES_PER_BLOCK, 1, img);   
        }
    }
    fclose(in); 
    return 0; 
}