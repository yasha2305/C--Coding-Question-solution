#include<stdio.h>
int main(){
    int b,h;
    int area;
    printf("Enter the base and height of the triangle:");
    scanf("%d %d",&b,&h);
    area = 0.5*b*h;
    printf("THE AREA OF TRIANGLE IS: %d",area);
    return 0;
}