#include "board.h"
#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  board_t board;
  init_board(&board);
  char * ptr;
  if (set_board_file(&board, ".board_data")) {
    return 1;
  }
  ptr = print_board(&board);
  printf("%s", ptr);
  free(ptr);

  int row = 1;
  int col = 4;
  //printf("5 - 5 mod 3 = %d\n", 5 - 5%3);
  printf("Possibilites for row %d col %d are: 0x%x\n", row, col, board.grid[row][col].poss);
  find_possible_values(&board, row, col);
  printf("Possibilites for row %d col %d are: 0x%x\n", row, col, board.grid[row][col].poss);
  return 0;
}