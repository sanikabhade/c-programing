#include <stdio.h>

int factorial(int n)
{
    if (n == 0)        // base condition
        return 1;
    else
        return n * factorial(n - 1);  // recursive call
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial = %d", factorial(num));
    return 0;
}