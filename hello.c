#include <stdio.h>
#include <cs50.h>

int main(void)
{
//Prompt user for name
    string name = get_string("What is your name?\n");
//Say hello user
    printf("hello, %s\n", name);
}