#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Odd numbers from 1 to %d are:\n", n);

    for(i = 1; i <= n; i++) {
        if(i % 2 != 0) {      // condition for odd number
            printf("%d ", i);
        }
    }

    return 0;
}