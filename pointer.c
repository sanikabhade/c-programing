#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;

    *p = 20;   // change value of x using pointer

    printf("x = %d", x);

    return 0;
}