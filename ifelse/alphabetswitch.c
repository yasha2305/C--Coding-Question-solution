#include<stdio.h>
int main(){
    char ch;
    printf("Enter a Character:");
    scanf("%c", &ch);
    switch(ch){
        case 'a' ... 'z':
        printf("The Given Character Is An Alphabet");
        break;
        case 'A' ... 'Z':
        printf("The Given Character Is An Alphabet");
        break;
        case '0' ... '9':
        printf("The Given Character Is A Digit");
        break;
        default:
        printf("It is a Special Character");

    }
    return 0;
}