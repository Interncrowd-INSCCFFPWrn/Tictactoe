#include <stdio.h>

// Function to print the tic-tac-toe board
void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int checkWin(char board[][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int moves = 0;

    while (1) {
        // Print the current state of the board
        printBoard(board);

        // Get the row and column from the current player
        int row, col;
        printf("Player %c's turn. Enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Adjust row and column to array indices
        row--;
        col--;

        // Check if the chosen cell is valid and empty
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Place the player's marker on the board
            board[row][col] = currentPlayer;
            moves++;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Check if the game is a draw
            if (moves == 9) {
                printf("It's a draw!\n");
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}