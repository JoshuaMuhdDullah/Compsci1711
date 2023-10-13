#include <stdio.h> 
#include <stdlib.h>

int main() {
    int arr[6] = {1,1,2,2,3,3}, i, j, temp;

    for (i = 0 ; i <= 5 ; i++) {
        temp = arr[i];

        for (j = i+1 ; j <=5 ; j++) {

            if (arr[j] == temp) {
                printf("duplicate of %d found\n", temp);
            }

        }
    }
    return 0;
}