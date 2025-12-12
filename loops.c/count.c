#include <stdio.h>
int main()
{
    int num, count = 0;
    printf("Enter Any number :");
    scanf("%d", &num);
    for ( ;num != 0; num/= 10)
    {
        count++;
    }
    printf("%d", count);
    return 0;
}