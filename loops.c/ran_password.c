#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$!";
    char password[11];

    srand(time(0));

    for (int i = 0; i < 10; i++)
        password[i] = chars[rand() % (sizeof(chars) - 1)];

    password[10] = '\0';

    printf("Random Password: %s\n", password);
    return 0;
}