#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long user_number = get_long("Enter a credit card number:\n");
    int counter = 0; 
    int second_2_last = 0;
    int last = 0;
    long n = user_number;
    int digit = 0;
    while (n > 0)
    {
        counter++;
        digit = n % 10;
        if (counter % 2 != 0)
        {
            last += digit;
        }
        else
        {
            if (floor((digit * 2) / 10) == 0)
            {
                second_2_last += digit * 2;
            }
            else
            {
                second_2_last += ((digit * 2) % 10 + 1);
            }
        } 
        n = floor(n / 10);
    }
    int final_sum = last + second_2_last;
    int  first_digit = floor(user_number / pow(10, (counter - 1)));
    int first_2_digits = floor(user_number / pow(10, (counter - 2)));
    if (final_sum % 10 == 0)
    {
        if (first_2_digits == 34 || first_2_digits == 37)
        {
            printf("AMEX\n"); 
        }
        else if (first_2_digits >= 51 && first_2_digits <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
}
