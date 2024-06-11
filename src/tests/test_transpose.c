#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_transpose_test_1) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  int res_code = s21_transpose(&A, &res);
  ck_assert_int_eq(res_code, OK);
  ck_assert_int_eq(res.matrix[0][0] == 1, 1);
  ck_assert_int_eq(res.matrix[0][1] == 3, 1);
  ck_assert_int_eq(res.matrix[1][0] == 2, 1);
  ck_assert_int_eq(res.matrix[1][1] == 4, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  int rows = 1, columns = 2;
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  int res_code = s21_transpose(&A, &res);
  ck_assert_int_eq(res_code, OK);
  ck_assert_int_eq(res.matrix[0][0] == 1, 1);
  ck_assert_int_eq(res.matrix[1][0] == 2, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int res_code = s21_transpose(&A, &res);
  ck_assert_int_eq(res_code, OK);
  ck_assert_int_eq(res.matrix[0][0] == 1, 1);
  ck_assert_int_eq(res.matrix[0][1] == 4, 1);
  ck_assert_int_eq(res.matrix[0][2] == 7, 1);
  ck_assert_int_eq(res.matrix[1][0] == 2, 1);
  ck_assert_int_eq(res.matrix[1][1] == 5, 1);
  ck_assert_int_eq(res.matrix[1][2] == 8, 1);
  ck_assert_int_eq(res.matrix[2][0] == 3, 1);
  ck_assert_int_eq(res.matrix[2][1] == 6, 1);
  ck_assert_int_eq(res.matrix[2][2] == 9, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_error_1) {
  int rows = 3, columns = 0;
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(rows, columns, &A);
  int res_code = s21_transpose(&A, &res);
  ck_assert_int_eq(res_code, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_error_2) {
  int rows = 3, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int res_code = s21_transpose(&A, NULL);
  ck_assert_int_eq(res_code, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_transpose(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_transpose");
  tc = tcase_create("s21_transpose");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_transpose_test_1);
    tcase_add_test(tc, s21_transpose_test_2);
    tcase_add_test(tc, s21_transpose_test_3);
    tcase_add_test(tc, s21_transpose_error_1);
    tcase_add_test(tc, s21_transpose_error_2);
    suite_add_tcase(s, tc);
  }

  return (s);
}
