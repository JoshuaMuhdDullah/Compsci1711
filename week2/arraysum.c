#include <stdio.h>

int main() {
    //initialize variable
    int array [5], sum = 0, i;

    //array values
    array[1] = 3, array[2] = 5, array[3] = 4, array[4] = 1, array[5] = 2;

    //calculate
    for ( i = 1 ; i <= 5 ; i++ ) {
        sum = sum + array[i];
    }

    //output
    printf("sum of array: %d\n", sum);
    return 0;
}