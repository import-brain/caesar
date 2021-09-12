#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 1)
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
            failure = true;
        }
    }

    if (failure == true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = "";

    char UPPER_LETTERS[27];

    char LOWER_LETTERS[27];

    UPPER_LETTERS[26] = '\0';

    LOWER_LETTERS[26] = '\0';

    for (int i = 65; i < 90; i++)
    {
        char charredUpperLetter = (char) (i);
        UPPER_LETTERS[i - 65] = charredUpperLetter;
    }

    for (int i = 97; i < 122; i++)
    {
        char charredLowerLetter = (char) (i);
        LOWER_LETTERS[i - 97] = charredLowerLetter;
    }

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            char currentLetter = plaintext[i];
            
            char newLetter;

            for (int j = 0; UPPER_LETTERS[j] != '\0'; j++)
            {
                if (currentLetter == UPPER_LETTERS[j])
                {
                    int tempLetter = ((j + argvToInt) % 26);

                    newLetter = UPPER_LETTERS[tempLetter];
                }
            }

            ciphertext[i] = newLetter;
        }
        else if (islower(plaintext[i]))
        {
            char currentLetter = plaintext[i];
            
            char newLetter;

            for (int j = 0; LOWER_LETTERS[j] != '\0'; j++)
            {
                if (currentLetter == LOWER_LETTERS[j])
                {
                    int tempLetter = ((j + argvToInt) % 26);

                    newLetter = LOWER_LETTERS[tempLetter];
                }
            }

            ciphertext[i] = newLetter;
        }
        else if (plaintext[i] == ' ')
        {
            ciphertext[i] = ' ';
        }
        else if (ispunct(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}