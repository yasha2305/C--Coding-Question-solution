#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check snakes and ladders
int checkSnakeLadder(int position)
{
    // Ladders
    if (position == 2) return 38;
    if (position == 7) return 14;
    if (position == 8) return 31;
    if (position == 15) return 26;
    if (position == 21) return 42;
    if (position == 28) return 84;
    if (position == 36) return 44;
    if (position == 51) return 67;
    if (position == 71) return 91;

    // Snakes
    if (position == 99) return 54;
    if (position == 95) return 72;
    if (position == 92) return 51;
    if (position == 87) return 36;
    if (position == 62) return 19;
    if (position == 64) return 60;
    if (position == 47) return 26;
    if (position == 49) return 11;
    if (position == 16) return 6;

    return position;
}

int main()
{
    int player1 = 0;
    int player2 = 0;
    int dice;
    int choice = 1;

    srand(time(NULL));

    printf("=====================================\n");
    printf("       SNAKE AND LADDER GAME\n");
    printf("=====================================\n");
    printf("Player 1 vs Player 2\n");
    printf("First player to reach 100 wins!\n\n");

    while (1)
    {
        // Player 1
        printf("\nPlayer 1 - Press 1 and Enter to roll: ");
        scanf("%d", &choice);

        dice = (rand() % 6) + 1;

        printf("Player 1 rolled: %d\n", dice);

        if (player1 + dice <= 100)
        {
            player1 += dice;
        }
        else
        {
            printf("You cannot move beyond 100!\n");
        }

        int newPosition = checkSnakeLadder(player1);

        if (newPosition > player1)
        {
            printf("Ladder! %d -> %d\n", player1, newPosition);
        }
        else if (newPosition < player1)
        {
            printf("Snake! %d -> %d\n", player1, newPosition);
        }

        player1 = newPosition;

        printf("Player 1 position: %d\n", player1);
        printf("Player 2 position: %d\n", player2);

        if (player1 == 100)
        {
            printf("\n=====================================\n");
            printf("       PLAYER 1 WINS!\n");
            printf("=====================================\n");
            break;
        }

        // Player 2
        printf("\nPlayer 2 - Press 1 and Enter to roll: ");
        scanf("%d", &choice);

        dice = (rand() % 6) + 1;

        printf("Player 2 rolled: %d\n", dice);

        if (player2 + dice <= 100)
        {
            player2 += dice;
        }
        else
        {
            printf("You cannot move beyond 100!\n");
        }

        newPosition = checkSnakeLadder(player2);

        if (newPosition > player2)
        {
            printf("Ladder! %d -> %d\n", player2, newPosition);
        }
        else if (newPosition < player2)
        {
            printf("Snake! %d -> %d\n", player2, newPosition);
        }

        player2 = newPosition;

        printf("Player 1 position: %d\n", player1);
        printf("Player 2 position: %d\n", player2);

        if (player2 == 100)
        {
            printf("\n=====================================\n");
            printf("       PLAYER 2 WINS!\n");
            printf("=====================================\n");
            break;
        }
    }

    return 0;
}