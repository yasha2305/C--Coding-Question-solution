// AREA AND CIRCUMFERENCE OF CIRCLE
#include<stdio.h>
int main(){
    int r;
    float pi= 3.14,area,circum;
    printf("ENTER THE VALUE OF RADIUS:");
    scanf("%d",&r); // taking input from user
    area = pi*r*r; // formula
    printf("THE AREA OF CIRCLE IS :%f",area);
    circum = 2*pi*r; //formula
    printf("/nTHE CIRCUMFERENCE OF CIRCLE IS:%f",circum);
    return 0;
}