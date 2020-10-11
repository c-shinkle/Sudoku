#pragma once

#include <stdint.h>

#define BOARD_SIZE 9
#define ROW_LENGTH 14
#define COL_LENGTH 13
#define BOARD_PRINT_BUFFER_SIZE ROW_LENGTH * COL_LENGTH +1

typedef struct cell_t
{
  uint8_t value;
  uint16_t poss;
} cell_t;

typedef struct board_t
{
  cell_t grid[BOARD_SIZE][BOARD_SIZE];
} board_t;

void init_board(board_t *board);
uint8_t set_board_string(board_t *board, char values[]);
uint8_t set_board_file(board_t *board, char *filename);
int get_cell_val(board_t *board, int row, int col);
uint8_t cell_has_poss(cell_t *cell, uint8_t val);
const char *print_row(board_t *board, char *buffer, uint8_t row);
const char *print_blank_row();
char *print_board(board_t *board, char board_buffer[]);
void elim_poss(cell_t *cell, uint8_t poss);
uint8_t count_poss(uint8_t poss);
uint8_t get_val_from_poss(uint16_t poss);