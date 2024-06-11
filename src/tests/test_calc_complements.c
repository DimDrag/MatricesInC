#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_calc_complements_test_1) {
  int rows1 = 2, cols1 = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows1, cols1, &A);
  A.matrix[0][0] = 57.0;
  A.matrix[0][1] = -55.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -79.0;
  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(C.matrix[0][0], -79.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], -2.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], 55.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], 57.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A = {0}, check = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &check);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 15;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 2;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 9;
  A.matrix[2][3] = 9;
  A.matrix[3][0] = -1;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 2;

  check.matrix[0][0] = -6;
  check.matrix[0][1] = 92;
  check.matrix[0][2] = -222;
  check.matrix[0][3] = 192;
  check.matrix[1][0] = 234;
  check.matrix[1][1] = 48;
  check.matrix[1][2] = 174;
  check.matrix[1][3] = -216;
  check.matrix[2][0] = 66;
  check.matrix[2][1] = -204;
  check.matrix[2][2] = 18;
  check.matrix[2][3] = 312;
  check.matrix[3][0] = -504;
  check.matrix[3][1] = 456;
  check.matrix[3][2] = 744;
  check.matrix[3][3] = -840;

  int ret_val = s21_calc_complements(&A, &C);
  ck_assert_int_eq(ret_val, OK);
  int eq = s21_eq_matrix(&C, &check);
  ck_assert_int_eq(eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_test_1_err) {
  matrix_t C = {0};
  int status = s21_calc_complements(NULL, &C);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_test_2_err) {
  matrix_t A = {0};
  int status = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_3_err) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_calc_complements");
  tc = tcase_create("s21_calc_complements");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_calc_complements_test_1);
    tcase_add_test(tc, s21_calc_complements_test_2);
    tcase_add_test(tc, s21_calc_complements_test_1_err);
    tcase_add_test(tc, s21_calc_complements_test_2_err);
    tcase_add_test(tc, s21_calc_complements_test_3_err);
    suite_add_tcase(s, tc);
  }

  return (s);
}
