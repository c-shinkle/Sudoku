#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  board_t board;
  init_board(&board);
  int i;
  for(i=0;i<BOARD_SIZE;i++)
    set_cell_val(&board, 0, i, i+1);
  const char * result = print_row(&board, 0);
  printf("%s\n", print_blank_row());
  printf("%s\n", result);
  free((void *)result);
  return 0;
}