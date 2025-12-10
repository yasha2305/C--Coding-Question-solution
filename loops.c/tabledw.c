// This program will print table of any desired number using do while loop
#include <stdio.h>
int main()
{
    int i = 1, n; // In while and Do while loop initialization is must
    printf("Enter Any Number for Which you want to print Table : ");
    scanf("%d", &n);

    do
    {
        int ans;
        ans = n * i;
        printf(" %d * %d = %d \n", n, i, ans);
        i++;
    } while (i < 11);
    return 0;
}
