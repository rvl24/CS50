#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h = get_int("Enter an integer between 1 and 8 (inclusive):\n");
    while (h > 8 || h < 4)
    {
        h = get_int("That's not quite right. Try again:\n");
    }
    if (h <= 8 && h >= 1)
    {
        int i = 0;
        while (i < h)
        {
            //make right side of pyramid
            
            for (int a = 1; a < h - i; a++)
            {
                printf(" ");
            }
            for (int b = 0; b <= i; b++)
            {
                printf("#");
            }
            
            // make the gap in the middle
            
            printf("  ");
            
            // make the left side of the pyramid
            
            for (int c = 0; c <= i; c++)
            {
                printf("#");
            }
            printf("\n");
            i++;
        }
    }        
}
