#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

void caesar(string input, int key);

int main(int argc, string argv[])
{

    bool failure = false;
    // if command line argument count is greater than 2 (including .caesar), return error message and exit main
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // iterate through every character in command line argument, if character is not a digit, set failure to true
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            failure = true;
        }
    }
    // if failure is true, return error message, and exit main
    if (failure == true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // convert command line argument to int
    int key = atoi(argv[1]);
    // gets plaintext from user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    caesar(plaintext, key);

    return 0;
}

void caesar(string input, int key)
{
    // for every character in input (plaintext, technically), perform ASCII calculations, print result
    // note to self: strlen() returns unsigned long
    for (unsigned long i = 0; i < strlen(input); i++)
    {
        if (islower(input[i]))
        {
            int asciiCurrent = (int) input[i];
            int asciiConverted = (((asciiCurrent - 97 + key) % 26) + 97);
            printf("%c", asciiConverted);
        }
        else if (isupper(input[i]))
        {
            int asciiCurrent = (int) input[i];
            int asciiConverted = (((asciiCurrent - 65 + key) % 26) + 65);
            printf("%c", asciiConverted);
        }
        else if (isspace(input[i]) || ispunct(input[i]))
        {
            printf("%c", input[i]);
        }
    }
    printf("\n");
}