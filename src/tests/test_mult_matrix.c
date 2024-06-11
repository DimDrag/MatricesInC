#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_mul_test_1) {
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

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -6;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -4;
  int status = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(B.columns, C.columns);
  ck_assert_int_eq(B.rows, C.rows);
  ck_assert_double_eq_tol(C.matrix[0][0], 0.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], 0.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], 0.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], 0.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mul_test_2) {
  int rows1 = 3;
  int columns1 = 3;
  int rows2 = 3;
  int columns2 = 1;
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 8;
  A.matrix[0][2] = -4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 9;
  A.matrix[1][2] = -5;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = -3;
  B.matrix[0][0] = 2;
  B.matrix[1][0] = -3;
  B.matrix[2][0] = 1;
  int status = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(B.columns, C.columns);
  ck_assert_int_eq(B.rows, C.rows);
  ck_assert_double_eq_tol(C.matrix[0][0], -18.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], -20.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][0], -16.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mul_matrix_1_err) {
  int rows = 2, columns = 3, rows2 = 2, columns2 = 3;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mul_matrix_2_err) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_mult_matrix(&A, NULL, &C);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mul_matrix_3_err) {
  matrix_t B = {0}, C = {0};
  s21_create_matrix(2, 2, &B);
  int status = s21_mult_matrix(NULL, &B, &C);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *suite_mult_matrix(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_mult_matrix");
  tc = tcase_create("s21_mult_matrix");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_mul_test_1);
    tcase_add_test(tc, s21_mul_test_2);
    tcase_add_test(tc, s21_mul_matrix_1_err);
    tcase_add_test(tc, s21_mul_matrix_2_err);
    tcase_add_test(tc, s21_mul_matrix_3_err);
    suite_add_tcase(s, tc);
  }

  return (s);
}
