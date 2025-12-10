// This program will print table of any desired number using  while loop
#include <stdio.h>
int main()
{
    int i = 1, n;
    printf("Enter Any Number for Which you want to print Table : ");
    scanf("%d", &n);
    while (i < 11)
    {
        int ans;
        ans = n * i;
        printf(" %d * %d = %d \n", n, i, ans);
        i++;
    }
    return 0;
}
