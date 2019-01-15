#include "board.h"
#include <stdio.h>

int main(int argc, char * argv[])
{
  board_t board;
  init_board(&board);
  board.grid[0][0].value = 1;
  printf("%d\n", board.grid[0][0].value);
  return 0;
}