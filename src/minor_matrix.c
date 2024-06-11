#include "s21_matrix.h"

// returns minor matrix(n, m) of matrix A
void get_minor_matrix(matrix_t *A, int n, int m, matrix_t *result) {
  *result = NULL_MATRIX;
  int size = A->columns - 1;
  s21_create_matrix(size, size, result);
  // i - rows counter for A, k - rows counter for result
  // j - columns counter for A, l - columns counter for result
  for (int i = 0, k = 0; i < size + 1 && k < size; k += (i != n), i++) {
    for (int j = 0, l = 0; j < size + 1 && l < size; l += (j != m), j++) {
      result->matrix[k][l] = A->matrix[i][j];
    }
  }
}