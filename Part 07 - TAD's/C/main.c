#include <stdio.h>
#include "matrix.h"

int main() 
{
    Matrix* matrix1 = createMatrix(2, 2);
    setElement(matrix1, 0, 0, 1.0);
    setElement(matrix1, 0, 1, 2.0);
    setElement(matrix1, 1, 0, 3.0);
    setElement(matrix1, 1, 1, 4.0);
    printf("Matrix 1:\n");

    for (int i = 0; i < getNumRows(matrix1); i++) {
        for (int j = 0; j < getNumCols(matrix1); j++) {
            printf("%.1f ", getElement(matrix1, i, j));
        }
        printf("\n");
}

    Matrix* matrix2 = createMatrix(2, 2);
    fillMatrix(matrix2, 0.0, 1.0);
    printf("Matrix 2:\n");
    for (int i = 0; i < getNumRows(matrix2); i++) {
        for (int j = 0; j < getNumCols(matrix2); j++) {
            printf("%.1f ", getElement(matrix2, i, j));
        }
        printf("\n");
    }

    addMatrix(matrix1, matrix2);
    printf("Matrix 1 + Matrix 2:\n");
    for (int i = 0; i < getNumRows(matrix1); i++) {
        for (int j = 0; j < getNumCols(matrix1); j++) {
            printf("%.1f ", getElement(matrix1, i, j));
        }
        printf("\n");
    }

    destroyMatrix(matrix1);
    destroyMatrix(matrix2);

    return 0;

}