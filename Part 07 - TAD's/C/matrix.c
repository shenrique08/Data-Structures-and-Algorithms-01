#include <stdlib.h>
#include <time.h>
#include "matrix.h"

struct matrix {
    int rows;
    int cols;
    float** data;
};

Matrix* createMatrix(int rows, int cols) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = 0.0;
        }
    }
    return matrix;
}

void destroyMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void setElement(Matrix* matrix, int row, int col, float value) {
    matrix->data[row][col] = value;
}

float getElement(Matrix* matrix, int row, int col) {
    return matrix->data[row][col];
}

int getNumRows(Matrix* matrix) {
    return matrix->rows;
}

int getNumCols(Matrix* matrix) {
    return matrix->cols;
}

void fillMatrix(Matrix* matrix, float minVal, float maxVal) {
    srand(time(NULL));
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = ((float)rand()/(float)(RAND_MAX)) * (maxVal - minVal) + minVal;
        }
    }
}

void addMatrix(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return;
    }
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] += matrix2->data[i][j];
        }
    }
}