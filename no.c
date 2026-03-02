#include <stdio.h>

// Function to check prime
int isPrime(int n) {
    if (n <= 1) return 0;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    FILE *fin, *fout;
    int num;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Cannot open input file!\n");
        return 1;
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Cannot open output file!\n");
        return 1;
    }

    fprintf(fout, "Prime Number Results:\n\n");

    // Read numbers until file ends
    while (fscanf(fin, "%d", &num) != EOF) {
        if (isPrime(num))
            fprintf(fout, "%d is Prime\n", num);
        else
            fprintf(fout, "%d is Not Prime\n", num);
    }

    fclose(fin);
    fclose(fout);

    printf("All results saved in output.txt\n");
    return 0;
}
``