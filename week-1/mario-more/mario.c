#include <cs50.h>
#include <stdio.h>

void print_pyramids(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n >= 9);
    print_pyramids(n);
}

void print_pyramids(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
