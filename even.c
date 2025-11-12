#include <stdio.h>

int main() {
    int i, n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Even numbers from 1 to %d are:\n", n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}