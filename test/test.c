#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/board.h"

#define CU_ADD_TEST(suite, test) (CU_add_test(suite, #test, (CU_TestFunc)test))

void pass_test(void) {
	CU_PASS("Compilation success");
}

void init_board_test() {
  board_t board;
  int i, j;

  init_board(&board);
  for(i=0;i<BOARD_SIZE;i++) {
    for(j=0;j<BOARD_SIZE;j++) {
      if (board.grid[i][j].value) {
        CU_FAIL("All of board.grid's values weren't initialized to 0");
      }
    }
  }
  CU_PASS("All of board.grid's values were initialized to 0");
}

void getter_board_test() {
  board_t board;
  init_board(&board);
  CU_ASSERT_EQUAL(get_cell_val(&board, 0, 0), 0);
}

void print_row_test() {
  board_t board;
  init_board(&board);
  int i;
  for(i=0;i<BOARD_SIZE;i++)
    set_cell_val(&board, 0, i, i+1);
  const char * result = print_row(&board, 0);
  CU_ASSERT_STRING_EQUAL(result, "|123|456|789|");
}

void print_blank_row_test() {
  CU_ASSERT_STRING_EQUAL(print_blank_row(), "------------");
}

int main(int argc, char *argv[])
{
	if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();	
  
  CU_pSuite suite = CU_add_suite("compile_test", 0, 0);

  if (!suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

	CU_ADD_TEST(suite, pass_test);
  CU_ADD_TEST(suite, init_board_test);
  CU_ADD_TEST(suite, getter_board_test);
  CU_ADD_TEST(suite, print_blank_row_test);
  CU_ADD_TEST(suite, print_row_test);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return 0;
}