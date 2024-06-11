#include "s21_matrix.h"

// multiplicates matrix by scalar
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!check_matrix(A) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}