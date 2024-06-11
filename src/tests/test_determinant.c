#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_determinant_test_1) {
  int rows1 = 3, cols1 = 3;
  matrix_t A = {0};
  s21_create_matrix(rows1, cols1, &A);

  A.matrix[0][0] = -7.0;
  A.matrix[0][1] = 9.0;
  A.matrix[0][2] = 5.0;
  A.matrix[1][0] = -8.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 1.0;
  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 3.0;
  A.matrix[2][2] = 5.0;
  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, 144);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  int rows1 = 2, cols1 = 2;
  matrix_t A = {0};
  s21_create_matrix(rows1, cols1, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -6;
  double res = 0;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, 8);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_1_err) {
  double C = 0;
  int status = s21_determinant(NULL, &C);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_test_2_err) {
  int rows = 3, columns = 2;
  matrix_t A = {0};
  double C = 0;
  s21_create_matrix(rows, columns, &A);
  int status = s21_determinant(&A, &C);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_determinant");
  tc = tcase_create("s21_determinant");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_determinant_test_1);
    tcase_add_test(tc, s21_determinant_test_2);
    tcase_add_test(tc, s21_determinant_test_1_err);
    tcase_add_test(tc, s21_determinant_test_2_err);
    suite_add_tcase(s, tc);
  }

  return (s);
}
