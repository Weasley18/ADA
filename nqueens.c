#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int board[MAX], count = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() 
{
    int n;
    printf("Enter number of Queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    solveNQueens(0, n);
    printf("\nTotal Solutions: %d\n", count);
    return 0;
}