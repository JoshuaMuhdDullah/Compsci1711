#include <stdio.h>

int isPrime(int num)
{
    int count = 2;
    int flag;

    while (count != num) 
    {
        if (num % count == 0)
        {
            return 0;
        }
        count++;
    }
    return 1;
}

void main() 
{   
    int prime;
    prime = isPrime(12);
    printf("%d\n",prime);
}