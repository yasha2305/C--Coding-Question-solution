//Check whether a number is divisible by 5 and 11 or not.
#include <stdio.h>
int main()
{
    int num;
    printf("Enter Any Number:");
    scanf("%d", &num);
    if (num % 5== 0&& num % 11==0)
    {
        printf("%d Is Divisible By Both 5 and 11.",num);
    }
    else
    {
        printf("%d Is Not Divisible By Both 5 and 11.",num);
    }
   
    return 0;
}