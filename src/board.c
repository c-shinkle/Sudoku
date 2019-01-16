#include "board.h"
#include <string.h>
#include <stdlib.h>

static const board_t empty_struct;
const char * BLANK_ROW = "------------";

void init_board(board_t * board) {
  *board = empty_struct;
}

void set_cell_val(board_t * board, int row, int col, int val) {
  board->grid[row][col].value = val;
}

int get_cell_val(board_t * board, int row, int col) {
  return board->grid[row][col].value;
}

const char * print_row(board_t * board, int row) {
  int col, i;
  char * str = malloc(sizeof(char)*14);
  //error with malloc
  if (!str)
    return NULL;
  str[13] = 0;
  for(col=i=0;i<13;i++) {
    if (i%4==0) {
      str[i] = '|';
    } else {
      //ascii-48 == '0'
      str[i] = get_cell_val(board, row, col++) + 48;
    }
  }
  return str;
}

const char * print_blank_row() {
  return BLANK_ROW;
}

char * print_board(board_t * board) {
  return NULL;
}