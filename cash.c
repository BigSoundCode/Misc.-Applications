#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int remaining;
    float change;
    do
    {
        change = get_float("Enter change owed in dollars:\n");
    }

    while (change<0);
    //find remainder of varying levels of change amounts
    int number = 0;
    int cents = round(change * 100);
    int mod25 = cents % 25;
    int mod10 = mod25 % 10;
    int mod5 = mod10 % 5;





    //arithmetic to provide amount of coins to return
    if (cents % 25 == 0)
    {
        number = cents / 25;

    }
    //if not perfectly divisible to quarters, this finds out how many dimes
    else if (mod10 == 0)
    {
        number = round(cents / 25) + mod25 / 10;

    }
    //if remainder not perfectly divisible in dimes, finds out how many nickels
    else if (mod5 == 0)
    {
        number = round(cents / 25) + round(mod25 / 10) + mod10 / 5;

    }
    //finds out how many pennies and sums number coins requires
    else if (mod5 != 0)
    {
        number = round(cents / 25) + round(mod25 / 10) + round(mod10 / 5) + mod5;





    }

    printf("%i\n", number);































}