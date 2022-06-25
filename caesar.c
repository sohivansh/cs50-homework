#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

bool only_digits(string input);
char rotate(char C, int key);
int main(int argc, string argv[])
{
    //checks the number of arguments in the command line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //if the number of arguments is only 1
    else
    {
        //if the key is only numeric
        if (only_digits(argv[1]))
        {
            int key = atoi(argv[1]);
            //if key is non negative
            if (key >= 0)
            {
                string plain = get_string("plaintext:  ");
                printf("ciphertext: ");
                for (int j = 0; j < strlen(plain); j++)
                {
                    printf("%C",rotate(plain[j], key));
                }
                printf("\n");

            }
            else
            {
                printf("Usage: ./caesar key\n");
                printf("key should be non negative\n");
                return 1;
            }


        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }


    }

}

//function to check if it is only numeric
bool only_digits(string input)
{
    int false_count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 48 && input[i] <= 57)
        {
            false_count += 0;

        }
        else
        {
            false_count++;
        }

    }
    if (false_count >= 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//rotation function
char rotate(char C, int key)
{
    if (isalpha(C))
    {

            if (C >= 65 && C <= 90)
            {
                return (C - 65 + key)%26 + 65;

            }
            else
            {
                return (C - 97 + key)%26 + 97;

            }

    }
    else
    {
        return C;
    }
}
