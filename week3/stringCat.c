#include <stdio.h>

char str3[200];

int str_len(char string[])
{
    int count = 0;
    while (string[count] != '\0')
    {
        count++;
    }
    return count;
} 

char *concatStrings(char str1[], char str2[])
{
    int i;
    int count = 0;

    for (i = 0; i < str_len(str1); i++)
    {
        str3[count] = str1[i];
        count++;
    }

    for (i = 0; i < str_len(str2); i++)
    {
        str3[count] = str2[i];
        count++;
    }

    return str3;
}


void main()
{
    printf("%s\n",concatStrings("Hello ","World"));
}