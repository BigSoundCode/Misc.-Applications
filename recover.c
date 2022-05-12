#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //check for proper user input and return usage
    //if (argc != 1)
    //{
        //printf("Usage: ./recover image\n");
        //return 1;
    //}
    //Open original data file, return error to user if file is empty/doesn't exist
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // create file name for first recovered jpeg for initial test run of code. Will need to automate this.
    char *output = "001.jpg";
    //Open new file to write jpeg to.
    FILE *outptr = fopen(output, "w");
    if (output == NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not create %s.\n", output);
        return 5;
    }
    //malloc not working to solve segmentation fault
    char *s = malloc(100000);
    fread(&file, sizeof(BYTE), 1, file);

    for (int n = 0; n < 1000; n++)
    {
        fwrite(&s, sizeof(BYTE), 1, file);
    }
    free(s);



}