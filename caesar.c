#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
//Set up command line arguement

    //Argv needs to contain only 2 arguements

    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    //Argv needs to contain only digits

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./ceasar key\n");
            return 1;
        }
    }

//Convert key to integer

    int k = atoi(argv[1]);

//Prompt user for plaintext

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    //Convert to ciphertext & create loop for alphebet

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }

        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }

        else
        {
            printf("%c", plaintext[j]);
        }

    }
    printf("\n");
}
