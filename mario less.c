#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declares the variables

    int height;

    // asks for a user input between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //for iterating through row
    for (int row = 0; row < height; row++)
    {
        //for iterating through columns
        for (int column = 0; column < height; column++)
        {
            //conditioning for # and space
            if (row + column < height - 1)
            {
                printf(" ");

            }
            else
            {
                printf("#");
            }

        }
        printf("\n");

    }



}
