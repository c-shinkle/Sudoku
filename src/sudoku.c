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
  char *p = print_board(&board);
  puts(p);
  printf("%ld\n", strlen(p));
  free(p);
  return 0;
}