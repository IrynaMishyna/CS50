#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average_gray;
    //по высоте
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++) //по ширине
        {
            //get average of rgb value
            average_gray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.00);

            image[j][i].rgbtBlue = average_gray;
            image[j][i].rgbtGreen = average_gray;
            image[j][i].rgbtRed = average_gray;
        }
    }
    return;
}

// Convert image to sepia

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    for(int i = 0; i < width; i++)  
    {
        for(int j = 0; j < height; j++)
        {
            float sepiaRed = 0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue;
            float sepiaGreen = 0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue;
            float sepiaBlue = 0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue;
            
            int new_sepiaRed = round(sepiaRed);
            int new_sepiaGreen = round(sepiaGreen);
            int new_sepiaBlue = round(sepiaBlue);
            
            if(new_sepiaRed > 255)
            {
                new_sepiaRed = 255;
            }
            
            if(new_sepiaGreen > 255)
            {
                new_sepiaGreen = 255;
            }
            
            if(new_sepiaBlue > 255)
            {
                new_sepiaBlue = 255;
            }
            
            image[j][i].rgbtRed = new_sepiaRed;
            image[j][i].rgbtGreen = new_sepiaGreen;
            image[j][i].rgbtBlue = new_sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int k = 0; k < width/2; k++)
        {
            RGBTRIPLE tmp = image[i][k];
            image[i][k] = image[i][width - k - 1];
            image[i][width - k - 1] = tmp;
             
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    // int sumBlue;
    // int sumGreen;
    // int sumRed;
    // float counter;
    // //create a temporary table of colors to not alter the calculations
    // RGBTRIPLE temp[height][width];

    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < height; j++)
    //     {
    //         sumBlue = 0;
    //         sumGreen = 0;
    //         sumRed = 0;
    //         counter = 0.00;

    //         // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
    //         for (int k = -1; k < 2; k++)
    //         {
    //             if (j + k < 0 || j + k > height - 1)
    //             {
    //                 continue;
    //             }

    //             for (int h = -1; h < 2; h++)
    //             {
    //                 if (i + h < 0 || i + h > width - 1)
    //                 {
    //                     continue;
    //                 }

    //                 sumBlue += image[j + k][i + h].rgbtBlue;
    //                 sumGreen += image[j + k][i + h].rgbtGreen;
    //                 sumRed += image[j + k][i + h].rgbtRed;
    //                 counter++;
    //             }
    //         }

    //         // averages the sum to make picture look blurrier
    //         temp[j][i].rgbtBlue = round(sumBlue / counter);
    //         temp[j][i].rgbtGreen = round(sumGreen / counter);
    //         temp[j][i].rgbtRed = round(sumRed / counter);
    //     }
    // }

    // //copies values from temporary table
    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < height; j++)
    //     {
    //         image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
    //         image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
    //         image[j][i].rgbtRed = temp[j][i].rgbtRed;
    //     }
    // }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
     RGBTRIPLE temp[height][width];
    
    for(int i = 0; i < height; i++)
    {
        for(int k = 0; k < width; k++)
        {
            int count = 1;
            float sumRed = image[i][k].rgbtRed;
            float sumGreen = image[i][k].rgbtGreen;
            float sumBlue = image[i][k].rgbtBlue;
            
            if(i > 0 && k > 0)
            {
                sumRed += image[i - 1][k - 1].rgbtRed;
                sumGreen += image[i - 1][k - 1].rgbtGreen;
                sumBlue += image[i - 1][k - 1].rgbtBlue;
                count ++;
            }
            
            if(i > 0)
            {
                sumRed += image[i - 1][k].rgbtRed;
                sumGreen += image[i - 1][k].rgbtGreen;
                sumBlue += image[i - 1][k].rgbtBlue;
                count ++;
            }
            
            if(i > 0 && k < width - 1)
            {
                sumRed += image[i - 1][k + 1].rgbtRed;
                sumGreen += image[i - 1][k + 1].rgbtGreen;
                sumBlue += image[i - 1][k + 1].rgbtBlue;
                count ++;
            }
            
            if(k > 0)
            {
                sumRed += image[i][k - 1].rgbtRed;
                sumGreen += image[i][k - 1].rgbtGreen;
                sumBlue += image[i][k - 1].rgbtBlue;
                count ++;
            }
            
            if(k < width - 1)
            {
                sumRed += image[i][k + 1].rgbtRed;
                sumGreen += image[i][k + 1].rgbtGreen;
                sumBlue += image[i][k + 1].rgbtBlue;
                count ++;
            }
            
            if(i < height - 1 && k > 0)
            {
                sumRed += image[i + 1][k - 1].rgbtRed;
                sumGreen += image[i + 1][k - 1].rgbtGreen;
                sumBlue += image[i + 1][k - 1].rgbtBlue;
                count ++;
            }
            
            if(i < height - 1)
            {
                sumRed += image[i + 1][k].rgbtRed;
                sumGreen += image[i + 1][k].rgbtGreen;
                sumBlue += image[i + 1][k].rgbtBlue;
                count ++;
            }
            
            if(i < height - 1 && k < width - 1 )
            {
                sumRed += image[i + 1][k + 1].rgbtRed;
                sumGreen += image[i + 1][k + 1].rgbtGreen;
                sumBlue += image[i + 1][k + 1].rgbtBlue;
                count ++;
            }
            
            float averegeRed = sumRed/count;
            float averegeGreen = sumGreen/count;
            float averegeBlue = sumBlue/count;
            
            temp[i][k].rgbtRed = round(averegeRed);
            temp[i][k].rgbtGreen = round(averegeGreen);
            temp[i][k].rgbtBlue = round(averegeBlue);
            
            // printf("pixel: %i, %i\n", i, k);
            // printf("count: %i\n\n", count);
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
