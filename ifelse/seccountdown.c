#include <stdio.h>
#include <windows.h>
int main()
{
    int n;
    printf("Enter seconds : ");
    scanf("%d", &n);
    while (n > 0)
    {
        printf("%d \n", n);
        fflush(stdout);
        Sleep(1000);
        n--;
    }
    printf("Time's up ! \n");
    return 0;
}