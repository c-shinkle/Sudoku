#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "board.h"
#include "solver.h"

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
  unsigned char* b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;

  for (i = size - 1; i >= 0; i--)
  {
    for (j = 7; j >= 0; j--)
    {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  puts("");
}

int main(int argc, char** argv)
{
  board_t board;
  init_board(&board);
  if (set_board_file(&board, ".board_data")) {
    return 1;
  }

  uint8_t row = 1;
  uint8_t col = 4;
  populate_possible_values(&board, row, col);
  uint16_t poss = board.grid[row][col].poss;
  printBits(sizeof(poss), &poss);
  return 0;
}