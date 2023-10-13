#include <stdio.h>

int main() {
    //initialize variable
    int arr [4], finarr [4], i, count = 0;

    //initialize array
     arr[0] = 2, arr[1] = 3, arr[2] = 5, arr[3] = 4, arr[4] = 1;

    //swap places
    for ( i = 4 ; i >= 0 ; i-- ) {
        finarr[count] = arr[i];
        count++;
    }

    //output
    for ( i = 0 ; i <= 4 ; i++ ) {
        printf("%d\n", finarr[i]);
    }

    return 0;
}
