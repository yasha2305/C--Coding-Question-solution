#include <stdio.h>

int main() {
    int num = 153, temp, sum = 0, digit;

    temp = num;

    while(num > 0) {
        digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }

    if(temp == sum)
        printf("Armstrong");
    else
        printf("Not Armstrong");

    return 0;
}