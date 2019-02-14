#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long user_number = get_long("Number: ");
    int counter = 0; 
    int last = 0;
    int second_2_last = 0;
    long n = user_number;
    int digit = 0;
    while (n > 0)
    {
        //get last digit of number 
        digit = n % 10;
        //determine whether this digit belongs to the group of alternating digits starting w/ the last digit or the second-to-last digit. If last, add digit.
        if (counter % 2 == 0)
        {
            last += digit;
        }
        else
            //determine whether digit*2 is greater than 10; if so, add 1 and ones-place digit to second-to-last group's total. If not, add digit*2
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
        counter++;
        //lop a digit off n
        n = floor(n / 10);
    }
    int final_sum = last + second_2_last;
    int  first_digit = floor(user_number / pow(10, (counter - 1)));
    int first_2_digits = floor(user_number / pow(10, (counter - 2)));
    //check if total divisible evenly by 10, then check other conditions
    if (final_sum % 10 == 0)
    {
        if ((first_2_digits == 34 || first_2_digits == 37) && counter == 15)
        {
            printf("AMEX\n"); 
        }
        else if ((first_2_digits >= 51 && first_2_digits <= 55) && counter == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (first_digit == 4 && (counter == 13 || counter == 16))
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
