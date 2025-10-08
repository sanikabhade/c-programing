#include <stdio.h>

int main() {
    char ch;

    // Print uppercase letters
    for (ch = 'A'; ch <= 'Z'; ch++) {
        printf("%c ", ch);
    }

    printf("\n");

    // Print lowercase letters
    for (ch = 'a'; ch <= 'z'; ch++) {
        printf("%c ", ch);
    }

    printf("\n");

    return 0;
}
