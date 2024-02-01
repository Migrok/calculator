#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "s21_smart_calc.h"

Suite* calc_suite(void);

int main() {
  int no_failed = 0;
  Suite* s;
  SRunner* runner;
  srand(time(NULL));

  s = calc_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 0;
}

START_TEST(test_calculate_plus_1) {
  char expression[] = "123 + 2";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 125);
}
END_TEST

START_TEST(test_calculate_plus_2) {
  char expression[] = "1 + 1 + 1 + 1 + 1 + 1 + 1";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 7);
}
END_TEST

START_TEST(test_calculate_minus_1) {
  char expression[] = "123 - 23";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 100);
}
END_TEST

START_TEST(test_calculate_minus_2) {
  char expression[] = "1 - 1 - 1 - 1 - 1 - 1 - 1";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, -5);
}
END_TEST

START_TEST(test_calculate_mul_1) {
  char expression[] = "33 * 3";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 99);
}
END_TEST

START_TEST(test_calculate_mul_2) {
  char expression[] = "2 * 2 * 2 * 2 * 2 * 32";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 1024);
}
END_TEST

START_TEST(test_calculate_div_1) {
  char expression[] = "10000 / 10";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 1000);
}
END_TEST

START_TEST(test_calculate_div_2) {
  char expression[] = "64 / 4 / 2 / 8";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 1);
}
END_TEST

START_TEST(test_calculate_div_3) {
  char expression[] = "64 / 0";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert(result == INFINITY);
}
END_TEST

START_TEST(test_calculate_mod_1) {
  char expression[] = "10000 % 2";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 0);
}
END_TEST

START_TEST(test_calculate_mod_2) {
  char expression[] = "13 % 5 % 2";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, 1);
}
END_TEST

START_TEST(test_calculate_unar_minus_1) {
  char expression[] = "-5 + (-3 * 2) - (-4 / 2)";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq(result, -9);
}
END_TEST

START_TEST(test_calculate_unar_minus_2) {
  char expression[] = "-sin(1) + 8 * 3 - 46 / (- 2)";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, 46.1585291, 0.0000001);
}
END_TEST

START_TEST(test_calculate_unar_minus_3) {
  char expression[] = "(-2) - (-2) + (-5) - 3 * ((-1) + 2 + (-3) ^ 3)";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, 73, 0.0000001);
}
END_TEST

START_TEST(test_calculate_functions_1) {
  char expression[] = "sin(-1) + cos(1)";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, -0.3011686, 0.0000001);
}
END_TEST

START_TEST(test_calculate_functions_2) {
  char expression[] = "tan(1) + asin(1) + acos(1/2) + atan(1/3)";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, 4.4971521, 0.0000001);
}
END_TEST

START_TEST(test_calculate_functions_3) {
  char expression[] = "-35 - sqrt(49) + (log(1000) * ln(3))";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, -38.7041631, 0.0000001);
}
END_TEST

START_TEST(test_calculate_double_1) {
  char expression[] = "10.5 + (-1.8)";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, 8.7, 0.0000001);
}
END_TEST

START_TEST(test_calculate_double_2) {
  char expression[] = "-(-100)^2";
  char* rpn1 = convertToRPN(expression);
  double result = evaluateRPN(rpn1);
  free(rpn1);
  ck_assert_double_eq_tol(result, -10000, 0.0000001);
}
END_TEST

Suite* calc_suite(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("Calc");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_calculate_plus_1);
  tcase_add_test(tc_core, test_calculate_plus_2);
  tcase_add_test(tc_core, test_calculate_minus_1);
  tcase_add_test(tc_core, test_calculate_minus_2);
  tcase_add_test(tc_core, test_calculate_mul_1);
  tcase_add_test(tc_core, test_calculate_mul_2);
  tcase_add_test(tc_core, test_calculate_div_1);
  tcase_add_test(tc_core, test_calculate_div_2);
  tcase_add_test(tc_core, test_calculate_div_3);
  tcase_add_test(tc_core, test_calculate_mod_1);
  tcase_add_test(tc_core, test_calculate_mod_2);
  tcase_add_test(tc_core, test_calculate_unar_minus_1);
  tcase_add_test(tc_core, test_calculate_unar_minus_2);
  tcase_add_test(tc_core, test_calculate_unar_minus_3);
  tcase_add_test(tc_core, test_calculate_functions_1);
  tcase_add_test(tc_core, test_calculate_functions_2);
  tcase_add_test(tc_core, test_calculate_functions_3);
  tcase_add_test(tc_core, test_calculate_double_1);
  tcase_add_test(tc_core, test_calculate_double_2);
  suite_add_tcase(s, tc_core);
  return s;
}
