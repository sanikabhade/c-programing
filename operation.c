#include <stdio.h>

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    // Input size of matrices
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Addition
    if(r1 == r2 && c1 == c2) {
        printf("\nMatrix Addition:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                result[i][j] = a[i][j] + b[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nAddition not possible (sizes not same)\n");
    }

    // Subtraction
    if(r1 == r2 && c1 == c2) {
        printf("\nMatrix Subtraction:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                result[i][j] = a[i][j] - b[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nSubtraction not possible (sizes not same)\n");
    }

    // Multiplication
    if(c1 == r2) {
        printf("\nMatrix Multiplication:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                result[i][j] = 0;
                for(k = 0; k < c1; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nMultiplication not possible (A columns != B rows)\n");
    }

    return 0;
}