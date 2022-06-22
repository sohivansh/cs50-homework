#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


//prototypes
int compute_words(string sentence);
int compute_letters(string sentence);
int compute_sentences(string sentence);


int main(void)
{
    //initializing number of each item
    int words = 0;
    int sentences = 0;
    int letters = 0;
    //user input
    string sentence = get_string("Text: ");
    //calling functions
    words = compute_words(sentence);
    letters = compute_letters(sentence);
    sentences = compute_sentences(sentence);
    //average letters per 100 words
    float L = ((float) letters / words) * 100;
    //average sentences per 100 words
    float S = ((float) sentences / words) * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    if (grade >= 16)
    {
        printf("Grade 16+\n");

    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int compute_words(string sentence)
{
    int words = 0;
    int length = strlen(sentence);
    //iterating through the sentence
    for (int i = 0; i < length; i++)
    {

        char C = sentence[i];
        //checking for space
        if (C == 32)
        {
            words++;
        }

    }
    return words + 1;
}


int compute_letters(string sentence)
{
    int letters = 0;
    int length = strlen(sentence);
    for (int i = 0; i < length; i++)
    {
        char C = sentence[i];
        //checking letters
        if ((C >= 65 && C <= 90) || (C >= 97 && C <= 122))
        {
            letters++;
        }

    }
    return letters;
}

int compute_sentences(string sentence)
{
    int sentences = 0;
    int length = strlen(sentence);
    for (int i = 0; i < length; i++)
    {
        char C = sentence[i];
        //checking exclamation, period, question mark
        if (C == 33 || C == 46 || C == 63)
        {
            sentences++;
        }
    }


    return sentences;
}
