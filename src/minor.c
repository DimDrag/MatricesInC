#include "s21_matrix.h"

// returns minor(n, m) of matrix A
double minor(matrix_t *A, int n, int m) {
  double result = 0;
  matrix_t minor_matrix;
  get_minor_matrix(A, n, m, &minor_matrix);
  s21_determinant(&minor_matrix, &result);
  s21_remove_matrix(&minor_matrix);
  return result;
}