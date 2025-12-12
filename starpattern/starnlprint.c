#include <stdio.h>
int main()
{
    int i,val;
    printf("Enter number of star you want to print : ");
    scanf("%d", &val);
    for (i = 1; i < val; i++)
    {
        printf("*\n");
    }
    return 0;
}