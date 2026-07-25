#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score_for(string player);

int main(void)
{
    string player_1 = get_string("Player 1: ");
    string player_2 = get_string("Player 2: ");

    int player1_score = get_score_for(player_1);
    int player2_score = get_score_for(player_2);

    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score_for(string player)
{
    //converting every character to lower case
    int length = strlen(player), score = 0;
    for(int i = 0; i < length; i++)
    {
        player[i] = tolower(player[i]);
        if isalpha(player[i])
        {
            score += scores[((int) player[i] - (int) 'a')];
        }
    }
    return score;
}

