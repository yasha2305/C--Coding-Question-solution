// This Program Will Tell Whether the Input Given Is A Vowel Or A Consonent
// Vowel = a,e,i,o,u
// Consonent = excluding vowel all are consonents
#include <stdio.h>
int main()
{
    char ch;
    printf("Enter Any Character: ");
    scanf("%c", &ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        printf("The Given Character Is A Vowel");
    }
    else
    {
        printf("The Given Character Is A Consonent");
    }
    return 0;
}
