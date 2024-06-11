#include "s21_matrix.h"

// checks if input matrix is incorrect
int check_matrix(matrix_t* A) {
  return A != NULL && A->rows > 0 && A->columns > 0 && A->matrix != NULL;
}