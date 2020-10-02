#pragma once

#include <stdint.h>

#define BOARD_SIZE 9

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
void set_cell_val(board_t *board, int row, int col, int val);
uint8_t set_board_string(board_t *board, const char *values);
int set_board_file(board_t *board, char *filename);
int get_cell_val(board_t *board, int row, int col);
uint8_t cell_has_poss(cell_t *cell, uint8_t val);
const char *print_row(board_t *board, char *buffer, uint8_t row);
const char *print_blank_row();
char *print_board(board_t *board);
cell_t *get_row(board_t *board, cell_t *buffer, int row);
cell_t *get_col(board_t *board, cell_t *buffer, int col);
void init_cell(cell_t *cell);
void elim_poss(cell_t *cell, uint8_t poss);