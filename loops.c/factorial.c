#include <stdio.h>
int main()
{
    /* logic
    5!= 5*4*3*2*1
    */
    int i,n,fact =1;
    printf("Enter Any Number :");
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    printf("Factorial is %d", fact);
    return 0;
}