#include <stdio.h>

int determinant3(int a[3][3]) {
    int det = 0;

    det =  a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
         - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
         + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);

    return det;
}

int determinant4(int a[4][4]) {
    int det = 0;
    int sub[3][3];

    for(int col = 0; col < 4; col++) {

        // Create submatrix (remove row 0 and column col)
        int subi = 0;
        for(int i = 1; i < 4; i++) {
            int subj = 0;
            for(int j = 0; j < 4; j++) {
                if(j == col) continue;
                sub[subi][subj] = a[i][j];
                subj++;
            }
            subi++;
        }

        int sign = (col % 2 == 0) ? 1 : -1;

        det += sign * a[0][col] * determinant3(sub);
    }

    return det;
}

int main() {
    int a[4][4];

    printf("Enter 4x4 matrix:\n");
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);

    int det = determinant4(a);

    printf("Determinant = %d\n", det);

    return 0;
}