// for loop
// This program will print the table of two using for loop
#include <stdio.h>
int main()
{
    int i;
    printf("The Table of Two is:\n");
    for (i = 1; i < 11; i++)
    {
        int ans;
        ans = 2 * i;
        printf(" 2 * %d = %d \n", i, ans);
    }
    return 0;
}