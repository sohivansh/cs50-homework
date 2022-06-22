#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //evaluates the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie\n");
    }

}

int compute_score(string word)
{
    //sets the initial score to 0
    int score = 0;
    //computes the length of the string
    int length = strlen(word);
    //iterates through the entered string
    for (int i = 0; i < length; i++)
    {
        //checks for alphabetical value
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
        {
            //converts the current index to uppercase
            char C = toupper(word[i]);
            //adds to the score
            score = score + POINTS[C - 65];

        }
        else
        {
            //returns 0 score if its a punctuation
            return score;
        }

    }
    return score;
}
