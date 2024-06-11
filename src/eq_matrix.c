#include "s21_matrix.h"

// compare two matrices
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (!check_matrix(A) || !check_matrix(B) || !check_compatibility(A, B)) {
    result_code = FAILURE;
  }
  for (int i = 0; i < A->rows && result_code; i++) {
    for (int j = 0; j < A->columns && result_code; j++) {
      result_code *= fabs(A->matrix[i][j] - B->matrix[i][j]) <= 1e-7;
    }
  }
  return result_code;
}