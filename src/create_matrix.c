#include "s21_matrix.h"

// creates new matrix & allocates memory for it
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(sizeof(double *), rows);
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(sizeof(double), columns);
  }
  return OK;
}