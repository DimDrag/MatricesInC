#include <stdio.h>

#include "s21_matrix.h"

// prints matrix
void s21_print_matrix(matrix_t A) {
  printf("%d %d\n", A.rows, A.columns);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%10.0lf ", A.matrix[i][j]);
    }
    printf("\n\n");
  }
}