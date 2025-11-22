#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int i, j, k, n;

    // Input size of square matrix
    printf("Enter the size of matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix A
    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix Addition
    printf("\nMatrix Addition:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Matrix Subtraction
    printf("\nMatrix Subtraction:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Matrix Multiplication
    printf("\nMatrix Multiplication:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            c[i][j] = 0;
            for(k = 0; k < n; k++) {
                c[i][j] += a[i][j] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}