#include "board.h"
#include <string.h>

static const board_t empty_struct;
board_t * board;

void init_board(board_t * board) {
  *board = empty_struct;
}

void set_cell_val(board_t * board, int row, int col, int val) {
  board->grid[row][col].value = val;
}

int get_cell_val(board_t * board, int row, int col) {
  return board->grid[row][col].value;
}