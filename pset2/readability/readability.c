#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.
// It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.

float count_sentence(string text);
int count_words(string text);
float count_letters(string text);
int main (void)
{
    string text = get_string("Text: ");
    // printf("%f letter(s)\n", count_letters(text));
    // printf("%i words(s)\n", count_words(text) );
    // printf("%f sentence(s)\n", count_sentence(text));
    
    float l = (100 * count_letters(text)) / (count_words(text));
    // printf("L  %f\n", l );
    
    float s = (100 * count_sentence(text)) / (count_words(text));
    // printf("S  %f\n", s );
    
    float index = 0.0588 * l - 0.296 * s - 15.8;
    // printf("index letter %.f\n", round(index) );
    
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
        printf("Grade %.f\n", round(index) );
    }
}

float count_letters(string text)
{
    float count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int i = 0,  n = strlen(text); i <= n; i++ )
    {
        if ( text[i] == ' ')
    {
        count++;
    }
    }
    return count;
}

float count_sentence(string text)
{
    float count = 0;
    for (int i = 0,  n = strlen(text); i <= n; i++ )
    {
        if ( text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
        count++;
    }
    }
    return count;
}