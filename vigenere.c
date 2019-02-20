#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define L_ALPHABET 26

void rotate_letter(char c, int k);

int main(int argc, string argv[])
{
    //check that command line argument was supplied
    if (argc != 2)
    {
        printf("Usage: ./caesar keyword\n");
        return 1;
    }
    else
    {
        string k = argv[1];
        int l_k = strlen(k);
        int j = 0;
        for (int i = 0; i < l_k; i++)  
        {
            if (isalpha(k[i]))
            {
                j++;
                //convert letters in 'k' to ints 0-26
                if isupper(k[i])
                {
                    k[i] -= 'A';
                }
                else
                {
                    k[i] -= 'a';
                }
            }
        }
        //check that all characters in 'k' are letters 
        if (j == l_k)
        { 
            string p = get_string("plaintext: ");
            int l_p = strlen(p);
            printf("ciphertext: ");
            for (int i = 0, m = 0; i < l_p; i++)
            {
                //keep 'k' counter looping through 'k'
                if (m == l_k)
                {
                    m = 0;
                }
                rotate_letter(p[i], k[m]);
                //only shift to next 'k' value if the current 
                //one was used on a letter
                if (isalpha(p[i]))
                {
                    m++;
                }
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar keyword\n");      
            return 1;
        }
    }
}
//rotate_letter shifts letter c by k spaces 
void rotate_letter(char c, int k)
{
    int n = 0;
    if isupper(c)
    {
        n = 'A' + (c - 'A' + k) % L_ALPHABET;
    }
    else if islower(c)
    {
        n = 'a' + (c - 'a' + k) % L_ALPHABET;
    }
    else
    {
        n = c;
    }
    printf("%c", n);
}
