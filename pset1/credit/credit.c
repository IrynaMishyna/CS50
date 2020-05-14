#include <cs50.h>
#include <stdio.h>

bool isValid(long card);
int main(void)
{
    long card = get_long("Number: ");
    int length = 2;
    long first_two = card;
    while (first_two > 99)
    {
        first_two /= 10;
        length++;
    }
    if (isValid(card) && length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (isValid(card) && length == 16 && first_two > 50 && first_two < 56)
    {
        printf("MASTERCARD\n");
    }
    else if (isValid(card) && (length == 13 || length ==16) && first_two > 39 && first_two < 50)
    {
        printf("VISA\n");
    }
    else
        printf("INVALID\n");
}

bool isValid(long card)
{
    int even_sum = 0;
    int odd_sum = 0;
    int i = 1;

    while (card > 0)
    {
        int num = card % 10;
        if (i % 2 == 0)
        {
            num *= 2;
            while (num > 0)
            {
                even_sum += num % 10;
                num /= 10; 
            }
        }
        else 
        {
            odd_sum += num;
        }
        i++;
        card /= 10;
    }
    if ((odd_sum + even_sum) % 10 == 0)
    {
        return true;
    }
    return  false;
}
