#include <stdio.h>

int main() {
    int mark;

    printf("Input mark: ");
    scanf("%d", &mark);

    if (mark >= 0 && mark <= 100)
    {
        if (mark == 0)
        {
            printf("zero\n");
        }
        else if (mark >= 70)
        {
            printf("distinction\n");
        }
        else if (mark >= 50)
        {
            printf("pass\n");
        }
        else
        {
            printf("fail\n");
        }
    }
    else
    {
        printf("Invalid mark\n");
    }
    return 0;
}