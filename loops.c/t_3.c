#include <stdio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void showBoard()
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

int winner()
{
    int win[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    for(int i = 0; i < 8; i++)
    {
        if(board[win[i][0]] == board[win[i][1]] &&
           board[win[i][1]] == board[win[i][2]])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int choice;
    int moves = 0;
    char player = 'X';

    printf("===== TIC TAC TOE =====\n");

    while(1)
    {
        showBoard();

        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &choice);

        if(choice < 1 || choice > 9)
        {
            printf("Invalid choice! Enter 1 to 9.\n");
            continue;
        }

        if(board[choice - 1] == 'X' || board[choice - 1] == 'O')
        {
            printf("Position already taken!\n");
            continue;
        }

        board[choice - 1] = player;
        moves++;

        if(winner())
        {
            showBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if(moves == 9)
        {
            showBoard();
            printf("Game Draw!\n");
            break;
        }

        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}