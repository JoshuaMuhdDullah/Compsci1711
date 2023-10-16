#include <stdio.h>

int main() {
    int num;
    num = 0;

    while (num != -1)
    {   
        printf("Input number: ");
        scanf("%d", &num);

        if (num >= 0 && num <= 100)
        {
            printf("Number is valid\n");
        }
        else if (num == -1)
        {
            printf("Code terminated\n");
        }
        else
        {
            printf("Number is invalid\n");
        }
    }

    return 0;
}