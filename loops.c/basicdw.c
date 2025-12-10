// do while
// This program will print the table of two using do while
#include <stdio.h>
int main()
{
    int i=1; // note in do while loop intialization is must
    printf("The Table of Two is:\n");

    do
    {
        int ans;
        ans = 2 * i;
        printf(" 2 * %d = %d \n", i, ans);
        i++;
    } while (i <= 10);
    return 0;
}