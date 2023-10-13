#include <stdio.h>
int main() 
{
    int i, j, count = 0;
    int arr1[3] = {1,2,3}, arr2[3] = {1,2,3}, arr3[6];

    for (i = 0 ; i < 6 ; i++) 
    {
        if (i/3 == 0)
        {
            arr3[i] = arr1[i];
        } else {
            arr3[i] = arr2[i%3];
        }
        printf("%d\n", arr3[i]);
    }

    
}