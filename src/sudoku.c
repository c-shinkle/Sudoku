#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  board_t board;
  init_board(&board);
  const char * result = print_board(&board);
  printf("%s", result);
  free((void *)result);
  return 0;
}