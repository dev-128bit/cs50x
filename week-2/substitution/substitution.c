#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string key;
char cipher(char ch);
int main(int argc, string argv[])
{
    if ((argc != 2))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int key_len  = strlen(argv[1]), index;
    key = argv[1];
    if (key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i = 0; i < key_len; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    string lower_case_key = argv[1];
    for(int i = 0; i < key_len; i++)
    {
        if(isupper(lower_case_key[i]))
        {
            lower_case_key[i] = tolower(lower_case_key[i]);
        }
    }
    for(int i = 0; i < key_len; i++)
    {
        //referenced from manual.cs50.io
        if(strrchr(lower_case_key, lower_case_key[i]) != strchr(lower_case_key, lower_case_key[i]))
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int plain_text_len = strlen(plaintext);
    for(int i = 0; i < plain_text_len; i++)
    {
        printf("%c", cipher(plaintext[i]));
    }
    printf("\n");
    return 0;
}

char cipher(char ch)
{
    int index;
    if(isalpha(ch))
    {
        if(islower(ch))
        {
            index = ((int) ch - 97);
            return (char) tolower(key[index]);
        }
        else
        {
            index = ((int) ch - 65);
            return (char) toupper(key[index]);
        }
    }
    else
    {
        return ch;
    }
}
