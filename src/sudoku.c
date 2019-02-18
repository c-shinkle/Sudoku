#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  board_t board;
  init_board(&board);
  const char * ptr = set_board_file(&board, ".board_data") ? 
    "Something went wrong with set_board_file" :
    print_board(&board);
  printf("%s\n", ptr);
  return 0;
}