// This program will print table of any desired number using for loop
#include <stdio.h>
int main()
{
    int i, n;
    printf("Enter Any Number for Which you want to print Table : ");
    scanf("%d", &n);
    printf("The Table of Two is:\n");
    for (i = 1; i < 11; i++)
    {
        int ans;
        ans = n * i;
        printf(" %d * %d = %d \n", n, i, ans);
    }
    return 0;
}
