#include "board.h"
#include <string.h>
#include <stdlib.h>

static const board_t empty_struct;
const char * BLANK_ROW = "------------\n";

void init_board(board_t * board) {
  *board = empty_struct;
}

void set_cell_val(board_t * board, int row, int col, int val) {
  board->grid[row][col].value = val;
}

int get_cell_val(board_t * board, int row, int col) {
  return board->grid[row][col].value;
}

const char * print_row(board_t * board, char * buffer, int row) {
  int col, i;
  for(col=i=0;i<13;i++) {
    if (i%4==0) {
      buffer[i] = '|';
    } else {
      //ascii-48 == '0'
      buffer[i] = get_cell_val(board, row, col++) + 48;
    }
  }
  buffer[13] = '\n';
  buffer[14] = 0;
  return buffer;
}

const char * print_blank_row() {
  return BLANK_ROW;
}

const char * print_board(board_t * board) {
  char buffer[14];
  char * result = malloc(sizeof(char)*183);
  result[0] = 0;
  int i, row;
  for(i=row=0;i<13;i++) {
    if (i%4==0) {
      strcat(result, print_blank_row());
    } else {
      strcat(result, print_row(board, buffer, row++));
    }
  }
  return result;
}

void set_board(board_t * board, int * values) {
  int row, col;
  for(row=0;row<BOARD_SIZE;row++) {
    for(col=0;col<BOARD_SIZE;col++) {
      set_cell_val(board, row, col, values[row*BOARD_SIZE+col]);
    }
  }
}

cell_t * get_row(board_t * board, cell_t * buffer, int row) {
  int i;
  for(i=0;i<BOARD_SIZE;i++) {
    buffer[i] = board->grid[row][i];
  }
  return buffer;
} 

cell_t * get_col(board_t * board, cell_t * buffer, int col) {
  int i;
  for(i=0;i<BOARD_SIZE;i++) {
    buffer[i] = board->grid[i][col];
  }
  return buffer;
}