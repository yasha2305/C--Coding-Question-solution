#include <stdio.h>
int main()
{
    int marks;
    printf("Enter your marks:");
    scanf("%d", &marks);
    switch (marks)
    {
    case 81 ... 100:
        printf("GRADE : Excellent A+");
        break;
    case 71 ... 80:
        printf("GRADE : Very Good A");
        break;
    case 61 ... 70:
        printf("GRADE : Good B");
        break;
    case 41 ... 60:
        printf("GRADE : Average C");
        break;
    case 40:
        printf("GRADE : Pass D");
        break;
    default:
        printf("You are Fail F");
        break;
    }
    return 0;
}
