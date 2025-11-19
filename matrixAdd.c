#include <stdio.h>

int main() {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int a[n][n], b[n][n], sum[n][n];

    // Input A
    printf("Enter Matrix A:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    // Input B
    printf("Enter Matrix B:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&b[i][j]);

    // Addition
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sum[i][j] = a[i][j] + b[i][j];

    // Display result
    printf("\nA + B = \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}