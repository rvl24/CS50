#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int L_ALPHABET = 26; 

int main(int argc, string argv[])
{
    //check that command line argument was supplied
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string k_string = argv[1];
        int l_k = strlen(k_string);
        int j = 0;
        //check that all characters of key are digits
        for (int i = 0; i < l_k; i++)  
        {
            if (isdigit(k_string[i]))
            {
                j++;
            }
        }
        if (j == l_k)
        {
            int k = atoi(k_string);
            string p = get_string("plaintext: ");
            int l_p = strlen(p);
            printf("ciphertext: ");
            for (int i = 0; i < l_p; i++)
            {
                int n = 0;
                //shift each letter in 'p' by k, treating uppercase &
                //lowercase differently b/c ASCII values are different 
                if isupper(p[i])
                {
                    n = 'A' + (p[i] - 'A' + k) % L_ALPHABET;
                }
                else if islower(p[i])
                {
                    n = 'a' + (p[i] - 'a' + k) % L_ALPHABET;
                }
                //leave nonalphabetic characters alone
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
