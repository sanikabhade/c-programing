#include <stdio.h>

int a = 100;   // Global variable

void show() {
    int b = 50;   // Local variable inside function
    printf("Inside function show():\n");
    printf("Global variable a = %d\n", a);
    printf("Local variable b = %d\n", b);
}

int main() {
    int c = 20;   // Local variable inside main

    printf("Inside main():\n");
    printf("Global variable a = %d\n", a);
    printf("Local variable c = %d\n", c);

    show();

    return 0;
}