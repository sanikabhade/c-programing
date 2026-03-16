#include <stdio.h>
#include <string.h>

int main() {
    char num1[1000], num2[1000];
    char result[1001];

    printf("Enter first large number: ");
    scanf("%s", num1);

    printf("Enter second large number: ");
    scanf("%s", num2);

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0, carry = 0;

    char temp[1001];

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;

        i--;
        j--;
    }

    // Reverse temp into result
    for (int m = 0; m < k; m++) {
        result[m] = temp[k - m - 1];
    }
    result[k] = '\0';

    printf("Sum = %s\n", result);

    return 0;
}