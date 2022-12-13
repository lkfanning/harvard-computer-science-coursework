#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

//Getting User Input

    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {

//Calculating Letters

        if (isalpha(text[i]))
        {
            letters++;
        }

//Calculating Words

        else if (text[i] == ' ')
        {
            words++;
        }

//Calculating Sentences

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

//Converting ints to floats so they compute in the equation

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

//Coleman-Liau index

    int index = round(0.0588 * L - 0.296 * S - 15.8);

// Output of grade-level

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}