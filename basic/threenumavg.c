//this code will print the average of three number
#include <stdio.h>
int main() {
    float a, b, c;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    printf("Average = %.2f", (a + b + c) / 3);
    return 0;
}
