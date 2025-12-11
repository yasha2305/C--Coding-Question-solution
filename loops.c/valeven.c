#include <stdio.h>
int main()
{
    int i, range;
    printf("Enter any range : ");
    scanf("%d", &range);
    for (i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {

            printf("Even number %d \n", i );
        }

        else
        {
            printf("Odd number %d\n", i);
        }
    }
    return 0;
}