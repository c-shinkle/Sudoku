#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  board_t board;
  init_board(&board);
  const char * ptr;
  if (set_board_file(&board, ".board_data")) {
    ptr = "Something went wrong with set_board_file";
  } else {
    ptr = print_board(&board);
  }
  printf("%s", ptr);
  return 0;
}