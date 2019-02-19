#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void rotate_letter(char c, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar keyword\n");
        return 1;
    }
    else
    {
        string k = argv[1];
        int j = 0;
        int l_key = strlen(k);
        for (int i = 0; i < l_key; i++)  
        {
            if (isalpha(k[i]))
            {
                j++;
                if isupper(k[i])
                {
                    k[i] = k[i] - 'A';
                }
                else
                {
                    k[i] = k[i] - 'a';
                }
            }
        }
        if (j == l_key)
        { 
            string p = get_string("plaintext: ");
            int l_plaintext = strlen(p);
            printf("ciphertext: ");
            for (int i = 0, m = 0; i < l_plaintext; i++, m++)
            {
                if (m == l_key)
                {
                    m = 0;
                }
                rotate_letter(p[i], k[m]);
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar keyword\n");       
        }
    }
}

void rotate_letter(char c, int k)
{
    int n = 0;
    if isupper(c)
    {
        n = 'A' + (c - 'A' + k) % 26;
    }
    else if islower(c)
    {
        n = 'a' + (c - 'a' + k) % 26;
    }
    else
    {
        n = c;
    }
    printf("%c", n);
}
