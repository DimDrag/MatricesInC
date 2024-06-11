#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_num_mul_test_1) {
  int rows1 = 2;
  int columns1 = 2;
  int rows2 = 2;
  int columns2 = 2;
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -6;
  int status = s21_mult_number(&A, 2, &C);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(B.columns, C.columns);
  ck_assert_int_eq(B.rows, C.rows);
  ck_assert_double_eq_tol(C.matrix[0][0], 4.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], -6.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], 8.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], -12.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_num_mul_test_2) {
  int rows1 = 4, cols1 = 5;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  A.matrix[0][0] = -13.0;
  A.matrix[0][1] = 23.0;
  A.matrix[0][2] = 68.0;
  A.matrix[0][3] = 9.0;
  A.matrix[0][4] = 70.0;
  A.matrix[1][0] = -86.0;
  A.matrix[1][1] = 82.0;
  A.matrix[1][2] = -14.0;
  A.matrix[1][3] = -42.0;
  A.matrix[1][4] = 100.0;
  A.matrix[2][0] = 97.0;
  A.matrix[2][1] = 74.0;
  A.matrix[2][2] = -27.0;
  A.matrix[2][3] = -2.0;
  A.matrix[2][4] = -36.0;
  A.matrix[3][0] = 92.0;
  A.matrix[3][1] = 85.0;
  A.matrix[3][2] = 31.0;
  A.matrix[3][3] = -10.0;
  A.matrix[3][4] = -33.0;
  int status = s21_mult_number(&A, -1, &C);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(C.matrix[0][0], 13, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], -23, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][2], -68, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][3], -9, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][4], -70, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], 86, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], -82, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][2], 14, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][3], 42, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][4], -100, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][0], -97, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][1], -74, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][2], 27, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][3], 2, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][4], 36, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[3][0], -92, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[3][1], -85, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[3][2], -31, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[3][3], 10, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[3][4], 33, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mul_num_1_err) {
  matrix_t A = {0};
  int status = s21_mult_number(&A, 2, NULL);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mul_num_2_err) {
  matrix_t A = {0};
  int status = s21_mult_number(NULL, 2, &A);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_mult_number");
  tc = tcase_create("s21_mult_number");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_num_mul_test_1);
    tcase_add_test(tc, s21_num_mul_test_2);
    tcase_add_test(tc, s21_mul_num_1_err);
    tcase_add_test(tc, s21_mul_num_2_err);
    suite_add_tcase(s, tc);
  }

  return (s);
}
