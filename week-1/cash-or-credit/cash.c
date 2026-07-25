#include <cs50.h>
#include <stdio.h>

int get_coins(float cents_owed);

int main(void)
{
    float change_owed;
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while(change_owed < 0.0);
    int coins_owe = get_coins(change_owed);
    printf("%i\n",coins_owe);
}

int get_coins(float cents_owed)
{
    int coins = 0;
    while(cents_owed != 0)
    {
        if (cents_owed >= 25)
        {
            coins += 1;
            cents_owed -= 25;
        }
        else if (cents_owed >= 10 && cents_owed < 25)
        {
            coins += 1;
            cents_owed -= 10;
        }
        else if (cents_owed >= 5 && cents_owed < 10)
        {
            coins += 1;
            cents_owed -= 5;
        }
        else
        {
            coins += cents_owed;
            cents_owed -= cents_owed;
        }
    }
    return coins;
}
