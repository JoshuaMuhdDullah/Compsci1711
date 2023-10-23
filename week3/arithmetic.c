#include <stdio.h>

float arithmetic(float num1, char operation, float num2)
{
    float calculation;
    switch (operation)
    {
        case '+':
            calculation = num1 + num2;
            printf("%f + %f = %f\n",num1, num2, calculation);
            break;

        case '-':
            calculation = num1 - num2;
            printf("%f - %f = %f\n",num1, num2, calculation);
            break;

        case '*':
            calculation = num1 * num2;
            printf("%f x %f = %f\n",num1, num2, calculation);
            break;
            
        case '/':
            if (num2 != 0)
            {
                calculation = num1/num2;
                printf("%f / %f = %f\n",num1, num2, calculation);
            }
            break;

        default:
            printf("Invalid operation\n");
    }
    return calculation;
}

void main() 
{
    arithmetic(2.1,'*',2.4);
}
//improvements to code; division by 0 needs to be checked
