
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("===== NUMBER GUESSING GAME =====\n");
    printf("Guess a number between 1 and 100!\n");

    while (1) {
        printf("\nEnter your guess: ");

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }

        attempts++;

        if (guess < number) {
            printf("Too low! Try a bigger number.\n");
        }
        else if (guess > number) {
            printf("Too high! Try a smaller number.\n");
        }
        else {
            printf("\nCongratulations! You won!\n");
            printf("Correct number: %d\n", number);
            printf("Total attempts: %d\n", attempts);
            break;
        }
    }

    return 0;
}
