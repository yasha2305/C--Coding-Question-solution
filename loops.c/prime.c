#include <stdio.h>
int main()
{
    int n, num = 1;
    printf("enter the number: ");
    scanf("%d",&n);
    // 10

    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            num = 0;
            break;
        }
        
    }

    if (num == 1)
    {
        printf("number is prime");
    }
    else{
        printf("number is not prime");
    }

    return 0;
    
    
}
