//this code will print the sum of all ements of a matrix 
#include <stdio.h>

int main() {
    int a[3][3], i, j;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d", &a[i][j]);

    printf("Diagonal elements:\n");

    for(i=0;i<3;i++)
        printf("%d ", a[i][i]);

    return 0;
}