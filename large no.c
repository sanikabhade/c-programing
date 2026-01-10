#include <stdio.h>

int main()
{
    long long a, b;

    printf("Enter two large numbers: ");
    scanf("%lld %lld", &a, &b);

    if (a > b)
        printf("Largest number = %lld", a);
    else if (b > a)
        printf("Largest number = %lld", b);
    else
        printf("Both numbers are equal");

    return 0;
}