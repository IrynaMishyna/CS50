#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[2])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++ )
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);

    string text = get_string ("plaintext:");

    printf("ciphertext:");
    for (int i = 0; i < text[i]; i++ )
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int upper = (text[i] - 64 + key) % 26 + 64;
                printf("%c", upper);


            }
            else if (islower(text[i]))
            {
                int lower = (text[i] - 96 + key) % 26 + 96;
                printf("%c", lower);


            }

        }
        else
        {
           printf("%c", text[i]);
        }

    }
      printf("\n");


}
