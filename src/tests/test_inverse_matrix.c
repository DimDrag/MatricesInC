#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_inverse_matrix_test_1) {
  int rows1 = 2, cols1 = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  A.matrix[0][0] = -374.0;
  A.matrix[0][1] = 466.0;
  A.matrix[1][0] = 582.0;
  A.matrix[1][1] = -919.0;
  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(C.matrix[0][0], -0.01267691119265044, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], -0.006428118189091518, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], -0.008028250613843912, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], -0.005159047645322376, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_test_1_err) {
  matrix_t C = {0};
  int status = s21_inverse_matrix(NULL, &C);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2_err) {
  matrix_t A = {0};
  int status = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3_err) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4_err) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 25;
  A.matrix[0][1] = 60;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 12;
  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

Suite *suite_inverse_matrix(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_inverse_matrix");
  tc = tcase_create("s21_inverse_matrix");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_inverse_matrix_test_1);
    tcase_add_test(tc, s21_inverse_matrix_test_1_err);
    tcase_add_test(tc, s21_inverse_matrix_test_2_err);
    tcase_add_test(tc, s21_inverse_matrix_test_3_err);
    tcase_add_test(tc, s21_inverse_matrix_test_4_err);
    suite_add_tcase(s, tc);
  }

  return (s);
}
