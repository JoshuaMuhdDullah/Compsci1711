#include "utils.h"

int main() 
{
    char filename [] = "data.txt";
    FILE *file = open_file(filename, "r");

    int n, sqr;
    printf("Input value of n: ");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        sqr = i*i;
        fprintf(file, "%d\n", sqr);
    }

    fclose(file);
    return 0;
}