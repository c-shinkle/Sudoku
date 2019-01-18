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
  char buffer[14];
  int i;
  for(i=0;i<BOARD_SIZE;i++)
    set_cell_val(&board, 0, i, i+1);
  const char * result = print_row(&board, buffer, 0);
  CU_ASSERT_STRING_EQUAL(result, "|123|456|789|\n");
}

void print_blank_row_test() {
  CU_ASSERT_STRING_EQUAL(print_blank_row(), "------------\n");
}

char * zero_board() {
  return 
    "------------\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "------------\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "------------\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "------------\n";
}

void print_board_test0() {
  board_t board;
  init_board(&board);
  char * test_board =
    "------------\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "------------\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "------------\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "|000|000|000|\n"
    "------------\n";
  CU_ASSERT_STRING_EQUAL(print_board(&board), test_board);
}

void print_board_test1() {
  board_t board;
  init_board(&board);
  int i;
  for(i=0;i<BOARD_SIZE;i++) {
    set_cell_val(&board, i, i, i+1);
  }
  CU_ASSERT_STRING_EQUAL(print_board(&board), 
    "------------\n"
    "|100|000|000|\n"
    "|020|000|000|\n"
    "|003|000|000|\n"
    "------------\n"
    "|000|400|000|\n"
    "|000|050|000|\n"
    "|000|006|000|\n"
    "------------\n"
    "|000|000|700|\n"
    "|000|000|080|\n"
    "|000|000|009|\n"
    "------------\n"  
  );
}

void print_board_test2() {
  board_t board;
  init_board(&board);
  int values[BOARD_SIZE*BOARD_SIZE] = {
    1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3,3,
    4,4,4,4,4,4,4,4,4,
    5,5,5,5,5,5,5,5,5,
    6,6,6,6,6,6,6,6,6,
    7,7,7,7,7,7,7,7,7,
    8,8,8,8,8,8,8,8,8,
    9,9,9,9,9,9,9,9,9
  };
  set_board(&board, (int *)values);
  char * test_board =
    "------------\n"
    "|111|111|111|\n"
    "|222|222|222|\n"
    "|333|333|333|\n"
    "------------\n"
    "|444|444|444|\n"
    "|555|555|555|\n"
    "|666|666|666|\n"
    "------------\n"
    "|777|777|777|\n"
    "|888|888|888|\n"
    "|999|999|999|\n"
    "------------\n";
  CU_ASSERT_STRING_EQUAL(print_board(&board), test_board);
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
  CU_ADD_TEST(suite, print_board_test0);
  CU_ADD_TEST(suite, print_board_test1);
  CU_ADD_TEST(suite, print_board_test2);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return 0;
}