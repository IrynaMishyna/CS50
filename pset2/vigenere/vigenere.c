#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isAlphaString(string str);
int shift(char c);

int main(int argc, string argv[])
{
    if (argc != 2 || !isAlphaString(argv[1]) )
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }


    int key_length = strlen(argv[1]);

    string text = get_string ("plaintext:");
    printf("ciphertext:");

    for (int i = 0, n = strlen(text), k = 0; i < n; i++ )
    {
        int key = shift(argv[1][k % key_length]);
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int upper = (text[i] - 65 + key) % 26 + 65;
                printf("%c", upper);
            }
            else if (islower(text[i]))
            {
                int lower = (text[i] - 97 + key) % 26 + 97;
                printf("%c", lower);
            }
            k++;
        }
        else
        {
           printf("%c", text[i]);
        }
    }


  printf("\n");

}

bool isAlphaString(string str)
{
    for(int i = 0, n = strlen(str); i < n; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

int shift(char c)
{
    int key = tolower(c)-97;
    return key;
}

