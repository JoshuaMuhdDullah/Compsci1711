#include <stdio.h>

int main()
{
    char str[6] = "Hello";
    int len = 0, i;

    while (str[len] != '\0')
    {
        len++;
    }


    for ( i = len-1 ; i >= 0 ; i-- )
    {
        printf("%c", str[i]);
    }
    printf("\n"); 

    return 0;
}