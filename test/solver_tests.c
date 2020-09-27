#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdint.h>
#include "../src/solver.h"
#include "solver_tests.h"

void naive_solver_test() {
  board_t board;
  init_board(&board);
  char* values =
    "058931427"
    "432678915"
    "917245683"
    "296354817"
    "581762349"
    "743819256"
    "129583764"
    "865497132"
    "374126598";
  char* solution = 
    "658931427"
    "432678915"
    "917245683"
    "296354817"
    "581762349"
    "743819256"
    "129583764"
    "865497132"
    "374126598";
  set_board_string(&board, values);
  naive_solver(&board);
  CU_ASSERT_STRING_EQUAL(print_board(&board), solution);
}

void populate_possible_values_test() {
  board_t board;
  uint8_t row = 1;
  uint8_t col = 4;

  init_board(&board);
  if (set_board_file(&board, ".board_data")) {
    CU_FAIL("No '.board_data' found");
  }
  populate_possible_values(&board, row, col);

  CU_TEST(board.grid[row][col].poss == 0b1111111000);
}
