#include <stdio.h>
int main() {

    //initialise variables
    int num, i, factorial = 1;

    //take input from user
    printf("num: ");
    scanf("%d", &num);

    //calculate
    for (i = 1 ; i <= num; i++) {
        factorial *= i;
    }

    //output
    printf("%d\n", factorial);
    return 0;

}