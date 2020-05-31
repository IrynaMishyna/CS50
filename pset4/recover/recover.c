#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check file name 
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image \n");
        return 1;
    }
    
    // open input file
    FILE *file = fopen(argv[1], "r");
    
    if(file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }
    
    //создаем новые переменные для нового файла
    
    FILE *img;
    char filename[7];
    unsigned char *buffer = malloc(512);
    int count = 0;
    
    while(fread(buffer, 512, 1, file))
    {
       if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
       {
           if (count > 0)
           {
               fclose(img);
           }
           
           sprintf (filename, "%03d.jpg", count);
           img = fopen(filename, "w");
           
           if(img ==NULL)
           {
               fclose(file);
               free(buffer);
               fprintf(stderr, "Could not create output JPG %s", filename);
               return 3;
           }
           count++;
       }
       
       if(count > 0)
       {
           fwrite(buffer, 512, 1, img);
       }
    }
    
    fclose(img);
    fclose(file);
    free(buffer);
    return 0;
}
