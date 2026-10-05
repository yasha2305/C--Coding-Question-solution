#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the board
void displayBoard() {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

// Check winner
int checkWinner() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Check draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;
        }
    }
    return 1;
}

int main() {

    int choice;
    char player = 'X';

    printf("=================================\n");
    printf("        TIC-TAC-TOE GAME\n");
    printf("=================================\n");

    while (1) {

        displayBoard();

        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &choice);

        // Validate position
        if (choice < 1 || choice > 9) {
            printf("Invalid position! Choose 1-9.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if position is already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        // Place X or O
        board[row][col] = player;

        // Check winner
        if (checkWinner()) {
            displayBoard();
            printf("🎉 Player %c WINS!\n", player);
            break;
        }

        // Check draw
        if (checkDraw()) {
            displayBoard();
            printf("🤝 GAME DRAW!\n");
            break;
        }

        // Change player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}