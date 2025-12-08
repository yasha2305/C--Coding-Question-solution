#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter Any Three Numbers :");
    scanf("%d %d %d", &a, &b, &c);
    if (a == b == c)
    {
        printf("all numbers are equal");
    }
    else if (a > b)
    {
        if (a > c)
        {
            printf("a is greater");
        }
        else
        {
            printf("c is greater");
        }
    }
    else
    {
        if (b > c)
        {
            printf("b is greater");
        }
        else
        {
            printf("c is greater");
        }
    }
}
