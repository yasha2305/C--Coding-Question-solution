#include <stdio.h>
int main()
{
    int year;
    printf("Enter Year:");
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        printf("It is a leap year");
    }
    else if (year % 100 != 0)
    {
        printf("It is not a leap year");
    }
   
    return 0;
}