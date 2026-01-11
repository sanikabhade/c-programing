#include <stdio.h>

int main()
{
    int num, lastTwo;

    printf("Enter a number: ");
    scanf("%d", &num);

    lastTwo = num % 100;   // Extract last two digits

    printf("Last two digits = %d", lastTwo);

    return 0;
}