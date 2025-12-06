#include <stdio.h>
int main()
{
    int marks;
    printf("Enter your marks:");
    scanf("%d", &marks);
    switch (marks)
    {
    case 81 ... 100:
        printf("Excellent A+");
        break;
    case 71 ... 80:
        printf("Very Good A");
        break;
    case 61 ... 70:
        printf("Good B");
        break;
    case 41 ... 60:
        printf("Average C");
        break;
    case 40:
        printf("Pass D");
        break;
    default:
        printf("You are Fail F");
        break;
    }
    return 0;
}