#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
   float a;

    do
    {
        a = get_float("Change owed: ");
    }
    while (a<0);

    int coins = round(a * 100);
    int coins_count = 0;

    while (coins>0)
    {
       if (coins>=25)
       {
            coins = coins - 25;
       }
       else if (coins>=10)
       {
           coins = coins - 10;

       }
       else if (coins>=5)
       {
        coins = coins - 5;
       }
       else
       {
           coins--;
       }

       coins_count++;
    }

    printf("%i\n",coins_count);
}