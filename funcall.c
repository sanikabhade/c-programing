#include <stdio.h>

// Function declaration
void add();

// Main function
int main() {
    add();   // Function call
    return 0;
}

// Function definition
void add() {
    int a = 10, b = 20;
    int sum = a + b;
    printf("Sum = %d", sum);
}