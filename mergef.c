#include "merge_files.h"
#include <stdio.h>
#include <stdlib.h>

int merge_augmented_matrix(const char* leftFile,
                           const char* rightFile,
                           const char* outFile)
{
    FILE *fl = fopen(leftFile, "r");
    FILE *fr = fopen(rightFile, "r");
    FILE *fo = fopen(outFile, "w");

    if (!fl) { printf("Error: cannot open %s\n", leftFile); return 0; }
    if (!fr) { printf("Error: cannot open %s\n", rightFile); fclose(fl); return 0; }
    if (!fo) { printf("Error: cannot create %s\n", outFile); fclose(fl); fclose(fr); return 0; }

    int rL, cL, rR, cR;

    if (fscanf(fl, "%d %d", &rL, &cL) != 2) {
        printf("Error: invalid header in %s\n", leftFile);
        fclose(fl); fclose(fr); fclose(fo);
        return 0;
    }

    if (fscanf(fr, "%d %d", &rR, &cR) != 2) {
        printf("Error: invalid header in %s\n", rightFile);
        fclose(fl); fclose(fr); fclose(fo);
        return 0;
    }

    if (rL != rR) {
        printf("Error: row mismatch. left rows=%d, right rows=%d\n", rL, rR);
        fclose(fl); fclose(fr); fclose(fo);
        return 0;
    }

    int rows = rL;
    int cols = cL + cR;

    // Write output header
    fprintf(fo, "%d %d\n", rows, cols);

    // Merge row by row (no need to store whole matrix)
    for (int i = 0; i < rows; i++) {

        // left row
        for (int j = 0; j < cL; j++) {
            double val;
            if (fscanf(fl, "%lf", &val) != 1) {
                printf("Error: not enough data in %s at row %d\n", leftFile, i);
                fclose(fl); fclose(fr); fclose(fo);
                return 0;
            }
            fprintf(fo, "%.10g", val);
            fprintf(fo, (j == cL - 1 && cR == 0) ? "\n" : " ");
        }

        // right row
        for (int j = 0; j < cR; j++) {
            double val;
            if (fscanf(fr, "%lf", &val) != 1) {
                printf("Error: not enough data in %s at row %d\n", rightFile, i);
                fclose(fl); fclose(fr); fclose(fo);
                return 0;
            }
            fprintf(fo, "%.10g", val);
            fprintf(fo, (j == cR - 1) ? "\n" : " ");
        }
    }

    fclose(fl);
    fclose(fr);
    fclose(fo);

    printf("Merged successfully -> %s\n", outFile);
    return 1;
}