#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_remove_matrix_test_1) {
  int rows = 4, columns = 4;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  int rows = -1, columns = -1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  int rows = 0, columns = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_remove_matrix_test_4) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

Suite *suite_remove_matrix(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_remove_matrix");
  tc = tcase_create("s21_remove_matrix");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_remove_matrix_test_1);
    tcase_add_test(tc, s21_remove_matrix_test_2);
    tcase_add_test(tc, s21_remove_matrix_test_3);
    tcase_add_test(tc, s21_remove_matrix_test_4);
    suite_add_tcase(s, tc);
  }

  return (s);
}
