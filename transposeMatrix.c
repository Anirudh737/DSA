#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix row-wise:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // create transposed matrix
    int transpose[cols][rows];
    for(i=0; i<cols; i++) {
        for(j=0; j<rows; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("The transposed matrix is:\n");
    for(i=0; i<cols; i++) {
        for(j=0; j<rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
