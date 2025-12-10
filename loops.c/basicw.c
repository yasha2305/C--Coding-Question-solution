// printing table of two using while loop
#include <stdio.h>
int main()
{
    int i = 1;
    printf("The Table of Two is:\n");
    while (i < 11)
    {
        int ans;
        ans = 2 * i;
        printf(" 2 * %d = %d \n", i, ans);
        i++;
    }
    return 0;
}