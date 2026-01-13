#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];

    printf("Enter first string: ");
    gets(s1);

    printf("Enter second string: ");
    gets(s2);

    if (strlen(s1) > strlen(s2))
        printf("Largest string is: %s", s1);
    else if (strlen(s2) > strlen(s1))
        printf("Largest string is: %s", s2);
    else
        printf("Both strings are of equal length");

    return 0;
}