#include <stdio.h>

// Function declaration
void add(int x, int y);

int main() {
    add(5, 7);   // Function call
    return 0;
}

// Function definition
void add(int x, int y) {
    int sum = x + y;
    printf("Sum = %d", sum);
}