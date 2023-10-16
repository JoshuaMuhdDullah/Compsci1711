#include <stdio.h>

int main() {
    int a;
    
    printf("input option: ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        printf("Option 1 selected\n");
        break;
    
    case 2:
        printf("Option 2 selected\n");
        break;
    
    case 3:
        printf("Option 3 selected\n");
        break;
    
    case 4:
        printf("Option 4 selected\n");
        break;
    
    case 5:
        printf("Option 5 selected\n");
        break;

    default:
        printf("Invalid option selected\n");
        break;
    }
    return 0;
}