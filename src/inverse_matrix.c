#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!check_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  double det = 0;
  s21_determinant(A, &det);
  if (fabs(det) <= 1e-6) {
    return CALCULATION_ERROR;
  }
  matrix_t algebraic_complements_matrix;
  s21_calc_complements(A, &algebraic_complements_matrix);
  matrix_t transpose_matrix;
  s21_transpose(&algebraic_complements_matrix, &transpose_matrix);
  s21_mult_number(&transpose_matrix, 1 / det, result);
  s21_remove_matrix(&algebraic_complements_matrix);
  s21_remove_matrix(&transpose_matrix);
  return OK;
}