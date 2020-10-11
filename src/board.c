#include "board.h"
#include <string.h>
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

uint8_t cell_has_poss(cell_t *cell, uint8_t val)
{
  return (cell->poss >> (val - 1)) & 1;
}

const char *print_row(board_t *board, char *buffer, uint8_t row)
{
  uint8_t col, i;
  for (col = i = 0; i < 13; i++)
  {
    buffer[i] = i % 4 == 0 ? '|' : board->grid[row][col++].value + '0';
  }
  buffer[13] = '\n';
  buffer[14] = 0;
  return buffer;
}

const char *print_blank_row()
{
  return BLANK_ROW;
}

char *print_board(board_t *board, char board_buffer[])
{
  uint8_t i, row;
  char row_buffer[ROW_LENGTH + 1];
  board_buffer[0] = 0;
  for (i = row = 0; i < 13; i++)
  {
    strcat(board_buffer, i % 4 == 0 ? print_blank_row() : print_row(board, row_buffer, row++));
  }
  return board_buffer;
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

uint8_t set_board_file(board_t *board, char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
    return 1;

  char board_buffer[BOARD_SIZE * BOARD_SIZE + 1];
  char line_buffer[BOARD_SIZE + 1];
  uint8_t i;

  board_buffer[0] = 0;
  for (i = 0; i < BOARD_SIZE; i++)
  {
    fscanf(file, "%s", line_buffer);
    strncat(board_buffer, line_buffer, BOARD_SIZE);
  }
  fclose(file);
  set_board_string(board, board_buffer);
  return 0;
}

void elim_poss(cell_t *cell, uint8_t val)
{
  if (val != 0)
  {
    cell->poss &= ~(1 << (val - 1));
  }
}

uint8_t count_poss(uint8_t poss)
{
  uint8_t counter = 0;
  while (poss)
  {
    counter += poss % 2;
    poss >>= 1;
  }
  return counter;
}

uint8_t get_val_from_poss(uint16_t poss)
{
  uint8_t val = 1;
  while (poss >>= 1)
  {
    ++val;
  }
  return val;
}
