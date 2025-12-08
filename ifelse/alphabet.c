//THIS PROGRAM WILL TELL YOU THAT THE GIVEN CHARACTER IS AN ALPHABET
#include <stdio.h>
int main()
{
    char ch;
    printf("Enter a Character:");
    scanf("%c", &ch);
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))

    {
        printf("The Given Character Is An Alphabet");
    }

    else
    {
        printf("It May Be A Digit Or A Special Character ");
    }
    return 0;
}
