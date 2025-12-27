#include <stdio.h>
int multiply(int a, int b)
{
    return a * b;
}
int main()
{
    int x = 5, y = 10;
    printf("result: %d", multiply(x, y));
    return 0;
}