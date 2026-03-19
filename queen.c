#include <stdio.h>
#include <stdlib.h>

#define N 8

int board[N][N];

// Function to print the board
void printBoard() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Check if placing queen at board[row][col] is safe
int isSafe(int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    // Check upper left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    // Check upper right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Function to solve 8 queen problem
int solveNQueen(int row) {
    int col;

    if (row == N)
        return 1; // All queens placed successfully

    for (col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; // Place queen

            if (solveNQueen(row + 1))
                return 1;

            board[row][col] = 0; // Backtrack
        }
    }

    return 0; // No solution found
}

int main() {
    int i, j;

    // Initialize board with 0
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueen(0)) {
        printf("Solution for 8 Queens Problem:\n");
        printBoard();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}