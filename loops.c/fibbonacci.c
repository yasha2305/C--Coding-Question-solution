#include <stdio.h>
int main()
{
    int num1=0, num2=1,num3,num4;
    printf("Enter Any Number :");
    scanf("%d", &num4);
    for (int i = 1; i <= num4; i++)
    {
        printf("Fibbonacci series is: %d\t", num1);
        printf("\nstep %d:num1 = %d -> printing %d\n\n", i, num1, num2);

        num3= num1 + num2;
        printf("next value of  num3 = num1 + num2 = %d +%d =%d\n\n", num1,num2, num3);
        num1 =num2;
        num2 = num3;
        printf("after shifting the value new num1 = %d, new num2 = %d",num1, num2);
    }
    return 0;
}