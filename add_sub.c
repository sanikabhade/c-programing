#include <stdio.h>

int main() {
    int a, b, temp;   // declaring variables

    // i. Read two integers, and perform addition, subtraction, and division without using a third variable
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Addition
    printf("\n(i) Without third variable:\n");
    printf("Addition = %d\n", a + b);

    // Subtraction
    printf("Subtraction = %d\n", a - b);

    // Division (checking to avoid divide by zero)
    if (b != 0)
        printf("Division = %d\n", a / b);
    else
        printf("Division not possible (divide by zero)\n");

    // ii. Read two integers, and perform addition, subtraction, and division using a third variable
    printf("\n(ii) With third variable:\n");
    printf("Enter two integers again: ");
    scanf("%d %d", &a, &b);

    temp = a + b;  // using third variable
    printf("Addition = %d\n", temp);

    temp = a - b;
    printf("Subtraction = %d\n", temp);

    if (b != 0) {
        temp = a / b;
        printf("Division = %d\n", temp);
    } else {
        printf("Division not possible (divide by zero)\n");
    }

    // iii. Swap two numbers using a third variable
    printf("\n(iii) Swap using third variable:\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    temp = a;   // use temp to hold one value
    a = b;
    b = temp;
    printf("After swapping: a = %d, b = %d\n", a, b);

    // iv. Swap two numbers without using a third variable
    printf("\n(iv) Swap without third variable:\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    a = a + b;   // add both numbers
    b = a - b;   // now b becomes the old value of a
    a = a - b;   // now a becomes the old value of b
    printf("After swapping: a = %d, b = %d\n", a, b);

    // v. Display the size of data types
    printf("\n(v) Size of data types:\n");
    printf("Size of int = %lu bytes\n", sizeof(int));
    printf("Size of float = %lu bytes\n", sizeof(float));
    printf("Size of double = %lu bytes\n", sizeof(double));
    printf("Size of char = %lu bytes\n", sizeof(char));

    return 0;
}