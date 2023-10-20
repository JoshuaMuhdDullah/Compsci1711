#include <stdio.h>

int str_len(char string[])
{
    int count = 0;
    while (string[count] != '\0')
    {
        count++;
    }
    return count;
} 

void main()
{   
    int len;
    printf("%d\n", str_len("Hello"));
}