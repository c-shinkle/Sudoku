#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdint.h>

#include "../src/solver.h"
#include "solver_tests.h"

void naive_solver_test_1()
{
  board_t actual_board;
  init_board(&actual_board);
  int err = set_board_file(&actual_board, "res/test_board_1");
  if (err)
    CU_FAIL("Failed to set board");
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
  char buffer[ROW_LENGTH * COL_LENGTH + 1];
  char *expected_printout = print_board(&expected_board, buffer);

  naive_solver(&actual_board);

  char *actual_printout = print_board(&actual_board, buffer);
  CU_ASSERT_STRING_EQUAL(actual_printout, expected_printout);
}

void populate_possible_values_test()
{
  board_t board;
  init_board(&board);
  uint8_t row = 1;
  uint8_t col = 4;
  if (set_board_file(&board, "res/board_data"))
  {
    CU_FAIL("No 'res/board_data' found");
  }

  populate_possible_values(&board, row, col);

  uint16_t actual_cell_poss = board.grid[row][col].poss;
  CU_ASSERT_EQUAL(actual_cell_poss, 0b111111000);
}
