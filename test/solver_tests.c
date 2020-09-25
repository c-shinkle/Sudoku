#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/board.h"
#include "../src/solver.h"

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

void find_possible_values_test() {
  board_t board;
  cell_t grid[BOARD_SIZE][BOARD_SIZE] = board.grid;
  int row = 1;
  int col = 4;

  init_board(&board);
  if (set_board_file(&board, ".board_data")) {
    CU_FAIL("No '.board_data' found");
  }
  find_possible_values(&board, row, col);
  // printf("0x%x", board.grid[row][col].poss);

  CU_TEST(grid[row][col].poss == 0x1c7);
}
