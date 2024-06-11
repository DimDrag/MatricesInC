#include "s21_matrix.h"

// return 1 if matrices are compatible
int check_compatibility(matrix_t* A, matrix_t* B) {
  return A->rows == B->rows && A->columns == B->columns;
}