#include <stdio.h>
int main()
{
    int marks;
    printf("Enter Marks: ");
    scanf("%d", &marks);

    if (marks >= 90)
    {
        printf("Grade: A");
    }
    else if (marks >= 75)
    {
        printf("Grade: B");
    }
    else if (marks >= 60)
    {
        printf("Grade: C");
    }
    else if (marks > 40)
    {
        printf("Grade: D");
    }
    else
    {
        printf("You are Fail");
    }
    return 0;
}