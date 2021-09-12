#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

string caesar(string input, string output, int key);

int main(int argc, string argv[])
{

    bool failure = false;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            failure = true;
        }
    }

    if (failure == true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int argvToInt = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    string ciphertext = "";

    string finaltext = caesar(plaintext, ciphertext, argvToInt);

    printf("ciphertext: %s\n", finaltext);
    return 0;
}

string caesar(string input, string output, int key)
{
    for (int i = 0; i < (int) strlen(input); i++)
    {
        if (isupper(input[i]))
        {
            int asciiCurrent = (int) input[i];
            int asciiConverted = (((asciiCurrent - 97 + key) % 26) + 97);
            output[i] = (char) asciiConverted;
        }
        else if (islower(input[i]))
        {
            int asciiCurrent = (int) input[i];
            int asciiConverted = (((asciiCurrent - 65 + key) % 26) + 65);
            output[i] = (char) asciiConverted;
        }
        else if (isspace(input[i]) || ispunct(input[i]))
        {
            output[i] = input[i];
        }
    }
    return output;
}