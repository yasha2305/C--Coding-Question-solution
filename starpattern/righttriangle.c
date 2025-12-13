#include <stdio.h>
int main()
{
    int i, j, rows = 1, column = 0;
    printf("Enter the number of rows and column : ");
    scanf("%d", &rows);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf(" \n");
    }
    return 0;
}