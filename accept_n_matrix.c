#include <stdio.h>

int main() {
    int n;

    // Input the size of matrix
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    int matrix[n][n];  // declare n×n matrix

    // Input elements
    printf("Enter the elements of the %d×%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display matrix
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}