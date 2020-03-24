#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, string argv[])
{

// check if single command-line argument in implemented and that it only contains numbers
    if (argc == 2 && isdigit(*argv[1]))
    {

// check for non-numeric key
        int argv_length = strlen(argv[1]);

        for (int i = 0; i < argv_length; i ++)
        {
            int nonint = isalpha(argv[1][i]);

            if (nonint != 0)
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }

// get the KEY converted into an int using atoi
        int k = atoi(argv[1]);

// get code from user input
        string code = get_string("plaintext: ");

// print out the encrypted message
        printf("ciphertext: ");

// iterate through the text to encrypt it
        for (int i = 0, n = strlen(code) ; i < n; i++)
        {
            if (code[i] >= 'a' && code[i] <= 'z')
            {
                printf("%c", (((code[i] - 'a') + k) % 26) + 'a'); // print out lowercase
            }
            else if (code[i] >= 'A' && code[i] <= 'Z')
            {
                printf("%c", (((code[i] - 'A') + k) % 26) + 'A'); // print out uppercase
            }
            else
            {
                printf("%c", code[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

}