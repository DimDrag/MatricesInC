#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!check_matrix(A) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  int size = A->columns;
  if (size == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = 0;
    for (int k = 0; k < size; k++) {
      matrix_t minor_matrix;
      get_minor_matrix(A, 0, k, &minor_matrix);
      double minor = 0;
      s21_determinant(&minor_matrix, &minor);
      s21_remove_matrix(&minor_matrix);
      *result += pow(-1, k % 2) * A->matrix[0][k] * minor;
    }
  }
  return OK;
}