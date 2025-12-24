//this code will copy one string to another string
#include <stdio.h>
int main()
{
    char s1[100], s2[100];
    int i = 0;

    printf("Enter string: ");
    gets(s1);   // very basic input

    while (s1[i] != '\0')
    {
        s2[i] = s1[i];
        i++;
    }

    s2[i] = '\0';

    printf("Copied string: ");
    puts(s2);

    return 0;
}
