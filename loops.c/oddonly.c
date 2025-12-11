#include <stdio.h>
int main()
{
    int i, range;
    printf("Enter any range : ");
    scanf("%d", &range);
    for (i = 1; i <= range; i++)
    {
        if (i % 2 != 0)
        {
            printf("odd number %d  \n", i);
        }
    }
    return 0;
}