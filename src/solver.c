#include "board.h"
#include "solver.h"

void naive_solver(board_t *board)
{
}

void populate_possible_values(board_t *board, uint8_t row, uint8_t col)
{
  cell_t *cell = &board->grid[row][col];
  init_cell(cell);

  uint8_t i;
  //check row
  for (i = 0; i < BOARD_SIZE; i++)
  {
    elim_poss(cell, board->grid[row][i].value);
  }
  //check col
  for (i = 0; i < BOARD_SIZE; i++)
  {
    elim_poss(cell, board->grid[i][col].value);
  }
  //check box
  uint8_t box_row = row / 3;
  uint8_t box_col = col / 3;
  for (i = 0; i < BOARD_SIZE; i++)
  {
    uint8_t grid_row = box_row * 3 + (i / 3);
    uint8_t grid_col = box_col * 3 + (i % 3);
    elim_poss(cell, board->grid[grid_row][grid_col].value);
  }
}
