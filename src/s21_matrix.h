#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <math.h>
#include <stdlib.h>

// RESULT CODES FOR OPERATIONS (EXCEPT MATRIX COMPARISON)
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

// RESULT CODES FOR BOOL MATRIX FUNCTIONS
#define SUCCESS 1
#define FAILURE 0

#define NULL_MATRIX \
  (matrix_t) { NULL, 0, 0 }

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// funcs mentioned in task
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// funcs for managing matrix
int check_matrix(matrix_t *A);
int check_compatibility(matrix_t *A, matrix_t *B);
void get_minor_matrix(matrix_t *A, int n, int m, matrix_t *result);
double minor(matrix_t *A, int n, int m);

// debugging funcs
void s21_print_matrix(matrix_t a);

#endif  // S21_MATRIX_H