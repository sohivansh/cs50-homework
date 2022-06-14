#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //takes user input
    string name = get_string("What is your name? \n");
    //prints the greeting with name 
    printf("hello, %s\n", name);
}
