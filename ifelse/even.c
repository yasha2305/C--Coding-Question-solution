#include <stdio.h>
int main()
{
    int n;
    printf("Enter Any Number: ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("%d is a Even Number", n);
    }
    else
    {
        printf("%d is an Odd Number", n);
    }
    return 0;
}