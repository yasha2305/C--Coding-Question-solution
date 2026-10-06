#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

int carX;
int enemyX;
int enemyY;
int score = 0;
int gameOver = 0;

void clearScreen()
{
    system("cls");
}

void drawGame()
{
    clearScreen();

    printf("\n       🏎️ CAR RACING GAME\n");
    printf("       Score: %d\n\n", score);

    for (int y = 0; y < HEIGHT; y++)
    {
        printf("|");

        for (int x = 0; x < WIDTH; x++)
        {
            if (y == HEIGHT - 2 &&
                (x == carX || x == carX + 1))
            {
                printf("A");
            }
            else if (y == enemyY &&
                     (x == enemyX || x == enemyX + 1))
            {
                printf("X");
            }
            else
            {
                printf(" ");
            }
        }

        printf("|\n");
    }

    printf("\nControls: A = Left | D = Right | Q = Quit\n");
}

void resetEnemy()
{
    enemyX = rand() % (WIDTH - 2);
    enemyY = 0;
}

int main()
{
    srand(time(NULL));

    carX = WIDTH / 2;
    resetEnemy();

    while (!gameOver)
    {
        drawGame();

        // Check keyboard input
        if (_kbhit())
        {
            char key = _getch();

            if (key == 'a' || key == 'A')
            {
                if (carX > 0)
                    carX -= 2;
            }

            if (key == 'd' || key == 'D')
            {
                if (carX < WIDTH - 2)
                    carX += 2;
            }

            if (key == 'q' || key == 'Q')
            {
                gameOver = 1;
                break;
            }
        }

        // Move enemy car
        enemyY++;

        // Collision detection
        if (enemyY == HEIGHT - 2)
        {
            if (enemyX == carX ||
                enemyX + 1 == carX ||
                enemyX == carX + 1)
            {
                gameOver = 1;
                break;
            }
        }

        // Enemy passed the player
        if (enemyY >= HEIGHT)
        {
            score++;
            resetEnemy();
        }

        Sleep(120);
    }

    clearScreen();

    printf("\n");
    printf("================================\n");
    printf("          GAME OVER!\n");
    printf("================================\n");
    printf("        Your Score: %d\n", score);
    printf("================================\n\n");

    return 0;
}