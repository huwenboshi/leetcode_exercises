#include <stdio.h>
#include <stdlib.h>

int min3(int a, int b, int c) {
    int tmp = a < b ? a : b;
    return tmp < c ? tmp : c;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int nrow = matrixRowSize;
    int ncol = matrixColSize;
    int* table = (int*) calloc((nrow+1)*(ncol+1), sizeof(int));
    int ans = 0;
    for(int i=0; i<nrow; i++) {
        for(int j=0; j<ncol; j++) {
            if(matrix[i][j] == '1') {
                int ii = i+1;
                int jj = j+1;
                int top = table[(ii-1)*(ncol+1)+jj];
                int left = table[ii*(ncol+1)+jj-1];
                int diag = table[(ii-1)*(ncol+1)+jj-1];
                int tmp = min3(top,left,diag)+1;
                table[ii*(ncol+1)+jj] = tmp;
                ans = ans>tmp ? ans : tmp;
            }
        }
    }
    for(int i=0; i<nrow+1; i++) {
        for(int j=0; j<ncol+1; j++) {
            printf("%d ", table[i*(ncol+1)+j]);
        }
        printf("\n");
    }
    return ans*ans;
}

int main() {
    char** matrix = (char**) calloc(4, sizeof(char*));
    char row0[] = {'1', '0', '1', '0', '0'};
    matrix[0] = row0;
    char row1[] = {'1', '0', '1', '1', '0'};
    matrix[1] = row1;
    char row2[] = {'1', '1', '1', '1', '1'};
    matrix[2] = row2;
    char row3[] = {'1', '0', '0', '1', '0'};
    matrix[3] = row3;
    int ans = maximalSquare(matrix, 4, 5);
    printf("%d\n", ans);
}
