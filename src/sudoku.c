#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "board.h"
#include "solver.h"

// Assumes little endian
void printBits(size_t const size, void const *const ptr)
{
  unsigned char *b = (unsigned char *)ptr;
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

int main(int argc, char **argv)
{
  board_t board;
  init_board(&board);
  char *values =
      "008931427"
      "432678915"
      "917245683"
      "296354817"
      "081762349"
      "743819256"
      "129583764"
      "865497132"
      "374126598";
  if (set_board_string(&board, values))
  {
    printf("Something went wrong setting the board\n");
    return 1;
  }
  char *before = print_board(&board);
  printf("Before:\n%s\n", before);
  free(before);
  naive_solver(&board);
  char *after = print_board(&board);
  printf("After:\n%s\n", after);
  free(after);
  return 0;
}