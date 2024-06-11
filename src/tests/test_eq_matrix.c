#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_eq_matrix_1) {
  int rows1 = 2, cols1 = 3;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows1, cols1, &B);
  A.matrix[0][0] = -2.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = -4.0;
  A.matrix[1][1] = -6.0;
  A.matrix[1][2] = 7.0;
  B.matrix[0][0] = -1.9999999425665;
  B.matrix[0][1] = 2.00000009840676;
  B.matrix[0][2] = 3.99999991639265;
  B.matrix[1][0] = -4.0000000294291;
  B.matrix[1][1] = -5.9999999675878;
  B.matrix[1][2] = 6.9999999752287;
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  int rows1 = 4, cols1 = 5;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows1, cols1, &B);

  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  int rows1 = 1, columns1 = 2;
  int rows2 = 2, columns2 = 1;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  int rows1 = 2, columns1 = 1;
  matrix_t A = {0};
  s21_create_matrix(rows1, columns1, &A);
  int res = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  int rows1 = 2, columns1 = 1;
  int rows2 = -12, columns2 = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_eq_matrix(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_eq_matrix");
  tc = tcase_create("s21_eq_matrix");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_eq_matrix_1);
    tcase_add_test(tc, s21_eq_matrix_2);
    tcase_add_test(tc, s21_eq_matrix_3);
    tcase_add_test(tc, s21_eq_matrix_4);
    tcase_add_test(tc, s21_eq_matrix_5);
    suite_add_tcase(s, tc);
  }

  return (s);
}
