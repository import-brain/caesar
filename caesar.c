#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int argvToInt = atoi(argv[1]);

    bool failure = false;

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) || ispunct(argv[1][i]) || !isdigit(argv[1][i]) || isblank(argv[1][i] || isspace(argv[1][i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = "";

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

string caesar(string input, string output)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (isupper(input[i]))
        {
            int asciiCurrent = (int) input[i];
            int asciiConverted = 

        }
    }
}