#include "board.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const char *BLANK_ROW = "-------------\n";

void init_board(board_t *board)
{
  uint8_t row, col;
  cell_t new_cell = {0, 0b111111111};
  for (row = 0; row < BOARD_SIZE; row++)
  {
    for (col = 0; col < BOARD_SIZE; col++)
    {
      board->grid[row][col] = new_cell;
    }
  }
}

void set_cell_val(board_t *board, int row, int col, int val)
{
  board->grid[row][col].value = val;
}

int get_cell_val(board_t *board, int row, int col)
{
  return board->grid[row][col].value;
}

uint8_t cell_has_poss(cell_t *cell, uint8_t val) {
  return (cell->poss >> (val - 1)) & 1;
}

const char *print_row(board_t *board, char *buffer, uint8_t row)
{
  uint8_t col, i;
  for (col = i = 0; i < 13; i++)
  {
    buffer[i] = i % 4 == 0 ? '|' : get_cell_val(board, row, col++) + '0';
  }
  buffer[13] = '\n';
  buffer[14] = 0;
  return buffer;
}

const char *print_blank_row()
{
  return BLANK_ROW;
}

char *print_board(board_t *board)
{
  uint8_t i, row;
  char buffer[15];
  char *result = malloc(sizeof(char) * 14 * 13 + 1); //1 byte char, 14 rows, 13 columns, 1 null terminator
  result[0] = 0;
  for (i = row = 0; i < 13; i++)
  {
    strcat(result, i % 4 == 0 ? print_blank_row() : print_row(board, buffer, row++));
  }
  return result;
}

uint8_t set_board_string(board_t *board, const char *str)
{
  if (strlen(str) != BOARD_SIZE * BOARD_SIZE)
    return 1;

  uint8_t row, col;
  for (row = 0; row < BOARD_SIZE; row++)
  {
    for (col = 0; col < BOARD_SIZE; col++)
    {
      set_cell_val(board, row, col, str[row * BOARD_SIZE + col] - '0');
    }
  }
  return 0;
}

int set_board_file(board_t *board, char *filename)
{
  FILE *file = fopen(filename, "r");
  char result[BOARD_SIZE * BOARD_SIZE + 1];
  char buffer[BOARD_SIZE + 1];
  int i;

  if (file == NULL)
    return 1;

  result[0] = 0;
  for (i = 0; i < BOARD_SIZE; i++)
  {
    fscanf(file, "%s", buffer);
    strncat(result, buffer, BOARD_SIZE);
  }
  fclose(file);
  set_board_string(board, result);
  return 0;
}

void elim_poss(cell_t *cell, uint8_t poss)
{
  if (poss != 0)
  {
    cell->poss &= ~(1 << (poss - 1));
  }
}
