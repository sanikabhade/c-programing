include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello, ";
    char str2[] = "World!";

    // Concatenate str2 to str1
    strcat(str1, str2);

    printf("Resulting string: %s\n", str1);

    return 0;
}
