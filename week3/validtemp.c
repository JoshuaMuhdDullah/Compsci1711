#include <stdio.h>

int main() {
    int temp;

    printf("Input temp: ");
    scanf("%d", &temp);

    if (temp >= -10 && temp <= 40)
    {
        printf("valid\n");
    }
    else
    {
        printf("invalid\n");
    }
    return 0;
}