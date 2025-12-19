#include <stdio.h>

int max(int a, int b);

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Maximum = %d", max(a, b));

    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}