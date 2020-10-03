#include "board.h"
#include "solver.h"
#include <string.h>

//Assumes board data are set and the board has a unique solution
uint8_t naive_solver(board_t *board)
{
  uint8_t row, col;
  for (row = 0; row < BOARD_SIZE; row++)
  {
    for (col = 0; col < BOARD_SIZE; col++)
    {
      populate_possible_values(board, row, col);
    }
  }
  for (row = 0; row < BOARD_SIZE; row++)
  {
    for (col = 0; col < BOARD_SIZE; col++)
    {
      if (get_cell_val(board, row, col) == 0)
      {
        uint8_t val = find_possibility(board, row, col);
        if (val == 0)
        {
          return 1;
        }
        else
        {
          set_cell_val(board, row, col, val);
        }
      }
    }
  }
  return 0;
}

void populate_possible_values(board_t *board, uint8_t row, uint8_t col)
{
  cell_t *cell = &board->grid[row][col];

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

uint8_t find_possibility(board_t *board, uint8_t row, uint8_t col)
{
  cell_t *cell = &board->grid[row][col];
  uint8_t possibilities = BOARD_SIZE;
  uint8_t i;
  for (i = 1; i <= possibilities; i++)
  {
    if (cell_has_poss(cell, i))
    {
      board_t copied_board;
      memcpy(&copied_board, board, sizeof(board_t));
      copied_board.grid[row][col].value = i;
      if (naive_solver(&copied_board) == 0)
      {
        return i;
      }
    }
  }
  return 0;
}
