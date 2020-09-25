#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/board.h"
#include "../src/solver.h"
#include "board_tests.h"
#include "solver_tests.h"

#define CU_ADD_TEST(suite, test) (CU_add_test(suite, #test, (CU_TestFunc)test))

void pass_test(void) {
	CU_PASS("Compilation success");
}

void add_board_tests(CU_pSuite * suite) {
  CU_ADD_TEST(*suite, pass_test);
  CU_ADD_TEST(*suite, init_board_test);
  CU_ADD_TEST(*suite, getter_board_test);
  CU_ADD_TEST(*suite, print_blank_row_test);
  CU_ADD_TEST(*suite, print_row_test);
  CU_ADD_TEST(*suite, print_board_test0);
  CU_ADD_TEST(*suite, print_board_test1);
  CU_ADD_TEST(*suite, print_board_test2);
  CU_ADD_TEST(*suite, set_board_string_test);
  CU_ADD_TEST(*suite, get_row_test);
  CU_ADD_TEST(*suite, get_col_test);
  CU_ADD_TEST(*suite, set_poss_test);
}

void add_solver_tests(CU_pSuite * suite) {
  CU_ADD_TEST(*suite, find_possible_values_test);
  // CU_ADD_TEST(*suite, naive_solver_test);
}

int main(int argc, char** argv)
{
	if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();	
  
  CU_pSuite board_suite = CU_add_suite("board_t suite", NULL, NULL);
  CU_pSuite solver_suite = CU_add_suite("solver suite", NULL, NULL);

  if (!board_suite || !solver_suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  add_board_tests(&board_suite);
	add_solver_tests(&solver_suite);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return 0;
}