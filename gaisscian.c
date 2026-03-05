#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-12

/* ---------- Utilities ---------- */
double** alloc_matrix(int r, int c) {
    double** m = (double**)malloc(r * sizeof(double*));
    if (!m) return NULL;
    for (int i = 0; i < r; i++) {
        m[i] = (double*)malloc(c * sizeof(double));
        if (!m[i]) return NULL;
    }
    return m;
}

void free_matrix(double** m, int r) {
    if (!m) return;
    for (int i = 0; i < r; i++) free(m[i]);
    free(m);
}

double** copy_matrix(double** src, int r, int c) {
    double** dst = alloc_matrix(r, c);
    if (!dst) return NULL;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dst[i][j] = src[i][j];
    return dst;
}

void swap_rows(double** m, int row1, int row2, int cols) {
    if (row1 == row2) return;
    for (int j = 0; j < cols; j++) {
        double tmp = m[row1][j];
        m[row1][j] = m[row2][j];
        m[row2][j] = tmp;
    }
}

void write_matrix(FILE* out, const char* title, double** m, int r, int c) {
    fprintf(out, "\n%s (%d x %d):\n", title, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fprintf(out, "%12.6e ", m[i][j]);
        }
        fprintf(out, "\n");
    }
}

void write_vector(FILE* out, const char* title, double* v, int n) {
    fprintf(out, "\n%s:\n", title);
    for (int i = 0; i < n; i++) {
        fprintf(out, "x[%d] = %.10f\n", i + 1, v[i]);
    }
}

/* ---------- File Reading ----------
   Expected format for left.txt:
   rows cols
   a11 a12 ... a1cols
   ...
   arows1 ... arowscols

   Expected format for right.txt:
   rows 1
   b1
   b2
   ...
   brows
*/
int read_matrix_file(const char* filename, double*** mat, int* r, int* c) {
    FILE* f = fopen(filename, "r");
    if (!f) return 0;

    if (fscanf(f, "%d %d", r, c) != 2) {
        fclose(f);
        return 0;
    }

    double** m = alloc_matrix(*r, *c);
    if (!m) {
        fclose(f);
        return 0;
    }

    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c; j++) {
            if (fscanf(f, "%lf", &m[i][j]) != 1) {
                free_matrix(m, *r);
                fclose(f);
                return 0;
            }
        }
    }

    fclose(f);
    *mat = m;
    return 1;
}

/* ---------- Build Augmented Matrix [A|b] ---------- */
double** build_augmented(double** A, int r, int cA, double** b, int rb, int cb, int* outCols) {
    if (r != rb) return NULL;
    if (cb != 1) return NULL;

    int c = cA + 1;
    *outCols = c;

    double** aug = alloc_matrix(r, c);
    if (!aug) return NULL;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < cA; j++) aug[i][j] = A[i][j];
        aug[i][cA] = b[i][0];
    }
    return aug;
}

/* ---------- Gaussian Elimination (in-place on augmented matrix) ---------- */
int gaussian_elimination(double** aug, int n, int cols, int pivoting) {
    // cols should be n+1
    for (int k = 0; k < n - 1; k++) {

        if (pivoting) {
            // partial pivot: find row with max abs in column k
            int best = k;
            double bestVal = fabs(aug[k][k]);
            for (int i = k + 1; i < n; i++) {
                double v = fabs(aug[i][k]);
                if (v > bestVal) {
                    bestVal = v;
                    best = i;
                }
            }
            if (bestVal < EPS) return 0; // singular / near singular
            swap_rows(aug, k, best, cols);
        } else {
            if (fabs(aug[k][k]) < EPS) return 0; // zero pivot
        }

        for (int i = k + 1; i < n; i++) {
            double factor = aug[i][k] / aug[k][k];
            aug[i][k] = 0.0; // explicitly make zero
            for (int j = k + 1; j < cols; j++) {
                aug[i][j] -= factor * aug[k][j];
            }
        }
    }

    if (fabs(aug[n - 1][n - 1]) < EPS) return 0;
    return 1;
}

/* ---------- Back Substitution ---------- */
int back_substitution(double** aug, int n, int cols, double* x) {
    // cols = n+1
    for (int i = n - 1; i >= 0; i--) {
        double sum = aug[i][n]; // RHS
        for (int j = i + 1; j < n; j++) {
            sum -= aug[i][j] * x[j];
        }
        if (fabs(aug[i][i]) < EPS) return 0;
        x[i] = sum / aug[i][i];
    }
    return 1;
}

/* ---------- Main ---------- */
int main(int argc, char* argv[]) {
    const char* leftFile  = "left.txt";
    const char* rightFile = "right.txt";
    const char* outFile   = "out.txt";

    if (argc >= 3) { leftFile = argv[1]; rightFile = argv[2]; }
    if (argc >= 4) { outFile = argv[3]; }

    double** A = NULL;
    double** b = NULL;
    int rA=0, cA=0, rb=0, cb=0;

    if (!read_matrix_file(leftFile, &A, &rA, &cA)) {
        printf("Error: Cannot read %s\n", leftFile);
        return 1;
    }
    if (!read_matrix_file(rightFile, &b, &rb, &cb)) {
        printf("Error: Cannot read %s\n", rightFile);
        free_matrix(A, rA);
        return 1;
    }

    if (rA != rb || cb != 1) {
        printf("Error: Dimension mismatch. A is %dx%d, b is %dx%d\n", rA, cA, rb, cb);
        free_matrix(A, rA);
        free_matrix(b, rb);
        return 1;
    }
    if (cA != rA) {
        printf("Error: A must be square for Gaussian elimination. A is %dx%d\n", rA, cA);
        free_matrix(A, rA);
        free_matrix(b, rb);
        return 1;
    }

    int augCols = 0;
    double** aug = build_augmented(A, rA, cA, b, rb, cb, &augCols);
    if (!aug) {
        printf("Error: Could not build augmented matrix.\n");
        free_matrix(A, rA);
        free_matrix(b, rb);
        return 1;
    }

    FILE* out = fopen(outFile, "w");
    if (!out) {
        printf("Error: Cannot write %s\n", outFile);
        free_matrix(A, rA);
        free_matrix(b, rb);
        free_matrix(aug, rA);
        return 1;
    }

    fprintf(out, "OUTPUT REPORT\n");
    write_matrix(out, "Augmented Matrix [A|b]", aug, rA, augCols);

    /* --- Solve without pivoting --- */
    double** augNoPivot = copy_matrix(aug, rA, augCols);
    double* x1 = (double*)malloc(rA * sizeof(double));

    fprintf(out, "\n\n==============================\n");
    fprintf(out, "Gaussian Elimination WITHOUT Pivoting\n");
    fprintf(out, "==============================\n");

    if (augNoPivot && x1 && gaussian_elimination(augNoPivot, rA, augCols, 0) &&
        back_substitution(augNoPivot, rA, augCols, x1)) {
        write_matrix(out, "Upper Triangular (No Pivot)", augNoPivot, rA, augCols);
        write_vector(out, "Solution (No Pivot)", x1, rA);
    } else {
        fprintf(out, "\nFailed (No Pivot): zero/near-zero pivot or singular matrix.\n");
    }

    /* --- Solve with pivoting --- */
    double** augPivot = copy_matrix(aug, rA, augCols);
    double* x2 = (double*)malloc(rA * sizeof(double));

    fprintf(out, "\n\n==============================\n");
    fprintf(out, "Gaussian Elimination WITH Partial Pivoting\n");
    fprintf(out, "==============================\n");

    if (augPivot && x2 && gaussian_elimination(augPivot, rA, augCols, 1) &&
        back_substitution(augPivot, rA, augCols, x2)) {
        write_matrix(out, "Upper Triangular (Pivot)", augPivot, rA, augCols);
        write_vector(out, "Solution (Pivot)", x2, rA);
    } else {
        fprintf(out, "\nFailed (Pivot): singular matrix.\n");
    }

    fclose(out);

    // cleanup
    free_matrix(A, rA);
    free_matrix(b, rb);
    free_matrix(aug, rA);
    free_matrix(augNoPivot, rA);
    free_matrix(augPivot, rA);
    free(x1);
    free(x2);

    printf("Done. Output saved to %s\n", outFile);
    return 0;
}