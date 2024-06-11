#include "test_matrix.h"

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

static int run_test_suite(Suite *test_suite) {
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed);
}

int main(void) {
  int number_failed = 0;
  Suite *suite_array[] = {
      suite_create_matrix(), suite_remove_matrix(),  suite_eq_matrix(),
      suite_sum_matrix(),    suite_sub_matrix(),     suite_mult_number(),
      suite_mult_matrix(),   suite_transpose(),      suite_calc_complements(),
      suite_determinant(),   suite_inverse_matrix(), NULL};

  for (size_t i = 0; suite_array[i]; ++i) {
    number_failed += run_test_suite(suite_array[i]);
  }

  return (number_failed ? EXIT_FAILURE : EXIT_SUCCESS);
}
