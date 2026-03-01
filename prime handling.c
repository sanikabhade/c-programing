#include <stdio.h>

// function to check prime
int isPrime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    FILE *fin, *fout;
    int num;

    // open input file
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // read number
    fscanf(fin, "%d", &num);
    fclose(fin);

    // open output file
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // check prime and write result
    if (isPrime(num))
        fprintf(fout, "%d is a Prime Number\n", num);
    else
        fprintf(fout, "%d is NOT a Prime Number\n", num);

    fclose(fout);

    printf("Result written to output.txt\n");

    return 0;
}