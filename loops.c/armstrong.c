#include <stdio.h>
#include <math.h>
int main()
{
    int num1, ori, count = 0, rem;
    double result = 0;
    printf("Enter any number :");
    scanf("%d", &num1);
    // armstrong number
    /*
    let suppose 153 is a number then it's armstrong will be
    1*1*1+5*5*5+3*3*3 = 153
     */
    ori = num1;
    int i = num1;
    for (; num1 != 0; num1 /= 10)
    {

        count++;
    }
    while (i != 0)
    {
        rem = i % 10;
        result += pow(rem, count);
        i = i / 10;
    }
    if (ori == (int)result)
    {
        printf("It is an armstrong number");
    }
    else
    {
        printf("It is not an armstrong number");
    }
    

    return 0;
}