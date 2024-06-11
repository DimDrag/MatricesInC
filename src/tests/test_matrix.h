#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include <check.h>

Suite *suite_create_matrix(void);  // done
Suite *suite_remove_matrix(void);  // done

Suite *suite_eq_matrix(void);  // done

Suite *suite_sum_matrix(void);   // done
Suite *suite_sub_matrix(void);   // done
Suite *suite_mult_number(void);  // done
Suite *suite_mult_matrix(void);  // done

Suite *suite_transpose(void);         // done
Suite *suite_calc_complements(void);  // done
Suite *suite_determinant(void);
Suite *suite_inverse_matrix(void);

#endif
