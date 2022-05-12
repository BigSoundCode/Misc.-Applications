#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word, int length);
int index;
int sum;

int main(void)
{


    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int n1 = strlen(word1);
    int n2 = strlen(word2);




    // Score both words
    int score1 = compute_score(word1, n1);
    int score2 = compute_score(word2, n2);
    //Prints Winning Player or Declares Tie
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }



    //Function to compute score is below.
}

int compute_score(string word, int length)
{


    sum = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (tolower(word[i]) == j + 97)
            {
                sum = sum + POINTS[j];

            }
        }


    }

    return sum;


}