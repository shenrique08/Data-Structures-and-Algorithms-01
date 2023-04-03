#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;

Matrix* createMatrix(int rows, int cols);
void destroyMatrix(Matrix* matrix);
void setElement(Matrix* matrix, int row, int col, float value);
float getElement(Matrix* matrix, int row, int col);
int getNumRows(Matrix* matrix);
int getNumCols(Matrix* matrix);
void fillMatrix(Matrix* matrix, float minVal, float maxVal);
void addMatrix(Matrix* matrix1, Matrix* matrix2);

#endif