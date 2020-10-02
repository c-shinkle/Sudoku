#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdint.h>
#include <stdlib.h>

#include "../src/solver.h"
#include "solver_tests.h"

void naive_solver_test()
{
  board_t actual_board;
  init_board(&actual_board);
  char *values =
      "008931427"
      "432678915"
      "917245683"
      "296354817"
      "081762349"
      "743819256"
      "129583764"
      "865497132"
      "374126598";
  set_board_string(&actual_board, values);

  board_t expected_board;
  init_board(&expected_board);
  char *solution =
      "658931427"
      "432678915"
      "917245683"
      "296354817"
      "581762349"
      "743819256"
      "129583764"
      "865497132"
      "374126598";
  set_board_string(&expected_board, solution);
  char *expected_printout = print_board(&expected_board);

  naive_solver(&actual_board);

  char *actual_printout = print_board(&actual_board);
  CU_ASSERT_STRING_EQUAL(expected_printout, actual_printout);
  free(actual_printout);
  free(expected_printout);
}

void populate_possible_values_test()
{
  board_t board;
  uint8_t row = 1;
  uint8_t col = 4;

  init_board(&board);
  if (set_board_file(&board, ".board_data"))
  {
    CU_FAIL("No '.board_data' found");
  }
  populate_possible_values(&board, row, col);

  CU_TEST(board.grid[row][col].poss == 0b1111111000);
}
