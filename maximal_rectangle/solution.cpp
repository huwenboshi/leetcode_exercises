#include <stdio.h>
#include <stdlib.h>

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int ans = 0;
    int* table = (int*)calloc(2*(matrixRowSize+1)*(matrixColSize+1),sizeof(int));
    for(int i=1; i<matrixRowSize+1; i++) {
        for(int j=1; j<matrixColSize+1; j++) {
            if(matrix[i-1][j-1] == '1') {
                int top_r = table[(i-1)*(matrixColSize+1)*2+2*j];
                int top_c = table[(i-1)*(matrixColSize+1)*2+2*j+1];
                int left_r = table[i*(matrixColSize+1)*2+2*(j-1)];
                int left_c = table[i*(matrixColSize+1)*2+2*(j-1)+1];
                int diag_r = table[(i-1)*(matrixColSize+1)*2+2*(j-1)];
                int diag_c = table[(i-1)*(matrixColSize+1)*2+2*(j-1)+1];
                int cur_r = 0;
                int cur_c = 0;
                table[i*(matrixColSize+1)*2+2*j] = cur_r;
                table[i*(matrixColSize+1)*2+2*j+1] = cur_c;
                if(cur_r*cur_c > ans) {
                    ans = cur_r*cur_c;
                }
            }
        }
    }
    
    for(int i=0; i<matrixRowSize+1; i++) {
        for(int j=0; j<matrixColSize+1; j++) {
            printf("(%d,%d) ", table[i*(matrixColSize+1)*2+2*j],table[i*(matrixColSize+1)*2+2*j+1]);
        }
        printf("\n");
    }
    return ans;
}

int main() {
    char** matrix = (char**) calloc(4, sizeof(char*));
    char row0[] = {'1', '0', '1', '0', '0'};
    matrix[0] = row0;
    char row1[] = {'1', '0', '1', '1', '1'};
    matrix[1] = row1;
    char row2[] = {'1', '1', '1', '1', '1'};
    matrix[2] = row2;
    char row3[] = {'1', '0', '0', '1', '0'};
    matrix[3] = row3;
    int ans = maximalRectangle(matrix, 4, 5);
    printf("%d\n", ans);
}
