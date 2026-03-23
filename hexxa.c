#include <stdio.h>

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Hexadecimal: %X", decimal);

    return 0;
}