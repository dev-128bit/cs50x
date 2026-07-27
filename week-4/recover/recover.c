#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 512
 
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover <file>\n");
        return 1;
    }

    FILE *memory_card = fopen(argv[1], "r");
    if(memory_card == NULL)
    {
        printf("File %s not found!\n", argv[1]);
        return 1;
    }

    uint8_t buffer[SIZE];
    int file_number = 0, flag = 1;
    char filename[8];
    FILE *image_file = NULL;
    
    while(fread(buffer, 1, SIZE, memory_card) == 512){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(flag)
            {
                flag = 0;
            }
            else
            {
                fclose(image_file);
            }
            sprintf(filename, "%03i.jpg", file_number);
            file_number++;
            image_file = fopen(filename, "w");
            fwrite(buffer, SIZE, 1, image_file);
        }
        else if(flag != 1)
        {
                fwrite(buffer, SIZE, 1, image_file);
        }
    }
    fclose(memory_card);
    fclose(image_file);
    return 0;
}
