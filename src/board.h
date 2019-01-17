#include "cell.h"
#define BOARD_SIZE 9

typedef struct {
  cell_t grid[BOARD_SIZE][BOARD_SIZE];
} board_t;

void init_board(board_t * board);
void set_cell_val(board_t * board, int row, int col, int val);
int get_cell_val(board_t * board, int row, int col);
const char * print_row(board_t * board, char * buffer, int row);
const char * print_blank_row();
const char * print_board(board_t * board);