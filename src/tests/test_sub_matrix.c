#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(s21_sub_test_1) {
  int rows1 = 3, cols1 = 3;
  int rows2 = 3, cols2 = 3;
  matrix_t A = {0}, C = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  A.matrix[0][0] = -7.0;
  A.matrix[0][1] = 9.0;
  A.matrix[0][2] = 5.0;

  A.matrix[1][0] = -8.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 1.0;

  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 3.0;
  A.matrix[2][2] = 5.0;

  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = 1.0;
  B.matrix[0][2] = 1.0;

  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 15.0;
  B.matrix[1][2] = 3.0;

  B.matrix[2][0] = 11.0;
  B.matrix[2][1] = -3.0;
  B.matrix[2][2] = -6.0;
  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(A.columns, C.columns);
  ck_assert_int_eq(B.rows, C.rows);
  ck_assert_double_eq_tol(C.matrix[0][0], -9.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], 8.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][2], 4.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], -10.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], -12.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][2], -2.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][0], -9.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][1], 6.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[2][2], 11.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_test_2) {
  int rows1 = 2, cols1 = 3;
  int rows2 = 2, cols2 = 3;
  matrix_t A = {0}, C = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 9.0;
  A.matrix[0][2] = -3.0;
  A.matrix[1][0] = -2.0;
  A.matrix[1][1] = -3.0;
  A.matrix[1][2] = -4.0;
  B.matrix[0][0] = -4.0;
  B.matrix[0][1] = -9.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = -2.0;
  B.matrix[1][1] = -8.0;
  B.matrix[1][2] = 7.0;
  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(A.columns, C.columns);
  ck_assert_int_eq(B.rows, C.rows);
  ck_assert_double_eq_tol(C.matrix[0][0], 9.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][1], 18.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[0][2], -4.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][0], 0.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][1], 5.0, 0.0000001);
  ck_assert_double_eq_tol(C.matrix[1][2], -11.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_1_err) {
  int rows = 2, columns = 5, rows2 = 2, columns2 = 2;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_2_err) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, C = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_sub_matrix(&A, NULL, &C);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_3_err) {
  matrix_t B = {0}, C = {0};
  s21_create_matrix(2, 2, &B);
  int status = s21_sub_matrix(NULL, &B, &C);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_4_err) {
  matrix_t B = {0}, A = {0};
  s21_create_matrix(2, 2, &B);
  int status = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_sub_matrix(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sub_matrix");
  tc = tcase_create("s21_sub_matrix");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, s21_sub_test_1);
    tcase_add_test(tc, s21_sub_test_2);
    tcase_add_test(tc, s21_sub_matrix_1_err);
    tcase_add_test(tc, s21_sub_matrix_2_err);
    tcase_add_test(tc, s21_sub_matrix_3_err);
    tcase_add_test(tc, s21_sub_matrix_4_err);
    suite_add_tcase(s, tc);
  }

  return (s);
}
