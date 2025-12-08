#include<stdio.h>
int main() {
    char f[40],m[40],l[40];
    printf("Enter Your Name:");
    scanf("%s %s %s",f,m,l);
    printf("abbreviated name: %c %c %s",f[0],m[0],l);
    return 0;

}
    