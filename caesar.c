#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        int j = 0;
        for (int i = 0; i < strlen(argv[1]); i++)  
        {
            if (isdigit(argv[1][i]))
            {
                j++;
            }
        }
        if (j == strlen(argv[1]))
        {
            int k = atoi(argv[1]); 
            string p = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0; i < strlen(p); i++)
            {
                int n = 0;
                if isupper(p[i])
                {
                    n = 'A' + (p[i] - 'A' + k) % 26;
                }
                else if islower(p[i])
                {
                    n = 'a' + (p[i] - 'a' + k) % 26;
                }
                else
                {
                    n = p[i];
                }
                printf("%c", n);
            }
            printf("\n");
        }
        else
        {
             printf("Usage: ./caesar key\n");       
        }
    }
    }
