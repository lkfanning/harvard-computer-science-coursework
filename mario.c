#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for input
    int h;
//Reprompt user for height if value given isn't between 1-8
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
//If height is within proper range, construct pyramids
    //For each row
    for (int i = 0; i < h; i++)
    {
        //For each column
        for (int j = 0; j < h - i - 1; j++)

            printf(" ");

        for (int j = 0; j < i + 1; j++)

            printf("#");

    printf("\n");
    }
}