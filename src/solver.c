#include "board.h"
#include "solver.h"

void naive_solver(board_t * board) {
  
}

void find_possible_values(board_t * board, int row, int col) {
  cell_t tmp = {0};

  int i;
  //check row
  for(i=0;i<BOARD_SIZE;i++) {
    if (board->grid[row][i].value) {
      set_poss(&tmp, board->grid[row][i].value);
    }
  }
  //check col
  for(i=0;i<BOARD_SIZE;i++) {
    if (board->grid[i][col].value) {
      set_poss(&tmp, board->grid[i][col].value);
    }
  }
  //check box
  for(i=0;i<BOARD_SIZE;i++) {
    int box_row = ((row / 3) * 3) + (i / 3);
    int box_col = ((col / 3) * 3) + (i % 3);
    if (board->grid[box_row][box_col].value) {
      set_poss(&tmp, board->grid[box_row][box_col].value);
    }
  }  
  //tmp will find all possible values that can't 
  //be in given cell. Then, you invert the bits
  //to get all possible values that can be in the given cell.
  board->grid[row][col].poss = tmp.poss ^ 0x1ff;  
}