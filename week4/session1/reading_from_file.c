#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char filename[] = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    int bufferlength = 100;
    char buffer[bufferlength];
    float num, sum = 0, count = 0;
    
    while (fgets(buffer, bufferlength, file) != NULL)
    {   
        num = strtof(buffer,NULL);
        sum += num;
        count++;
    }

    printf("Average of squares.dat is %f\n", sum/count);

    fclose(file);
    return 0;
}