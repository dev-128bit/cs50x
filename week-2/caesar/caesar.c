#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isnumber(string val);
int convert_to_int(string val);
char rotate(char ch, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        if(isnumber(argv[argc-1]))
        {
            int key = atoi(argv[argc-1]);
            string plaintext = get_string("plaintext:  ");
            printf("ciphertext: ");
            int len = strlen(plaintext);
            for(int i = 0; i < len; i++)
            {
                printf("%c", rotate(plaintext[i], key));
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        return 0;
    }
}

bool isnumber(string val)
{
    bool flag = false;
    int len = strlen(val);
    for(int i = 0; i < len; i++)
    {
        if(isdigit(val[i]))
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}

char rotate(char ch, int key)
{
    if (isalpha(ch))
    {
        if (isupper(ch))
        {
            return (char) (((((int) ch - 65) + key) % 26)+65);
        }
        else
        {
            return (char) (((((int) ch - 97) + key) % 26)+97);
        }
    }
    else
    {
        return ch;
    }
}
