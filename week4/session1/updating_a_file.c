#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[] = "numbers.dat";
    FILE *file = fopen(filename, "a+");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    float num = 2.910398;
    
    int bufferlength = 100;
    char buffer[bufferlength];
    
    
    while (fgets(buffer, bufferlength, file) != "\0")
    {   
        if (buffer == "\0")
        {
            //no newline
        }
        else
        {
            //with newline
        }
    }
    
    fclose(file);
    return 0;


}