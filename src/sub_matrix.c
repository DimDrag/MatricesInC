#include "s21_matrix.h"

// substracts matrices
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!check_matrix(A) || !check_matrix(B) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  if (!check_compatibility(A, B)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}