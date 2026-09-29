#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

int x, y;
int fruitX, fruitY;
int tailX[100], tailY[100];
int tailLength;
int score;
int gameOver;

enum Direction {
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum Direction dir;

void setup()
{
    gameOver = 0;
    dir = RIGHT;

    x = WIDTH / 2;
    y = HEIGHT / 2;

    srand(time(0));

    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;

    tailLength = 0;
    score = 0;
}

void draw()
{
    system("cls");

    // Top wall
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");

    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
            {
                printf("O");
            }
            else if (i == fruitY && j == fruitX)
            {
                printf("*");
            }
            else
            {
                int printed = 0;

                for (int k = 0; k < tailLength; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        printed = 1;
                        break;
                    }
                }

                if (!printed)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }

        printf("\n");
    }

    // Bottom wall
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");

    printf("\nScore: %d\n", score);
    printf("W A S D / Arrow Keys = Move | X = Exit\n");
}

void input()
{
    if (_kbhit())
    {
        int key = _getch();

        // Arrow keys
        if (key == 224)
        {
            key = _getch();

            switch (key)
            {
                case 72: // Up
                    if (dir != DOWN)
                        dir = UP;
                    break;

                case 80: // Down
                    if (dir != UP)
                        dir = DOWN;
                    break;

                case 75: // Left
                    if (dir != RIGHT)
                        dir = LEFT;
                    break;

                case 77: // Right
                    if (dir != LEFT)
                        dir = RIGHT;
                    break;
            }
        }
        else
        {
            switch (key)
            {
                case 'w':
                case 'W':
                    if (dir != DOWN)
                        dir = UP;
                    break;

                case 's':
                case 'S':
                    if (dir != UP)
                        dir = DOWN;
                    break;

                case 'a':
                case 'A':
                    if (dir != RIGHT)
                        dir = LEFT;
                    break;

                case 'd':
                case 'D':
                    if (dir != LEFT)
                        dir = RIGHT;
                    break;

                case 'x':
                case 'X':
                    gameOver = 1;
                    break;
            }
        }
    }
}

void logic()
{
    int previousX = tailX[0];
    int previousY = tailY[0];

    int previous2X;
    int previous2Y;

    // Move body
    if (tailLength > 0)
    {
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < tailLength; i++)
        {
            previous2X = tailX[i];
            previous2Y = tailY[i];

            tailX[i] = previousX;
            tailY[i] = previousY;

            previousX = previous2X;
            previousY = previous2Y;
        }
    }

    // Move head
    switch (dir)
    {
        case LEFT:
            x--;
            break;

        case RIGHT:
            x++;
            break;

        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        default:
            break;
    }

    // Hit wall
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
        gameOver = 1;
    }

    // Hit itself
    for (int i = 0; i < tailLength; i++)
    {
        if (x == tailX[i] && y == tailY[i])
        {
            gameOver = 1;
        }
    }

    // Eat fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;

        if (tailLength < 99)
            tailLength++;

        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}

int main()
{
    setup();

    while (!gameOver)
    {
        draw();
        input();
        logic();

        Sleep(120);
    }

    system("cls");

    printf("\n");
    printf("========================================\n");
    printf("              GAME OVER!\n");
    printf("========================================\n");
    printf("              Score: %d\n", score);
    printf("========================================\n");

    printf("\nPress any key to exit...");
    _getch();

    return 0;
}