#include <stdio.h>
int main()
{
    int num1, num2, result;
    char operator;
    printf("Enter Any Two Number");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("Enter Any Operator Like (+,-,*,/):");
    scanf(" %c", &operator);
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("The Addition of Number1 and Number2 is:%d ", result);
        break;
    case '-':
        result = num1 - num2;
        printf("The Subtraction of Number1 and Number2 is:%d ", result);
        break;
    case '*':
        result = num1 * num2;
        printf("The Multiplication of Number1 and Number2 is:%d", result);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Can't divide by Zero");
        }
        else
        {
            result = num1 / num2;
            printf("The Division of Number1 and Number2 is:%d", result);
        }
        break;
        
    default:
        printf("Invalid Operation");
        break;
    }
    return 0;
}