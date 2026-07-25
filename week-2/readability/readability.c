#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0, words, sentences = 0, no_of_spaces = 0, len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalnum(text[i]))
        {
            letters++;
        }
        else if (isblank(text[i]))
        {
            no_of_spaces++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        else
        {
            continue;
        }
    }
    words = no_of_spaces + 1;
    float L = ((float) letters / words) * 100.0;
    float S = ((float) sentences / words) * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}
