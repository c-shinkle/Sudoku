#include "cell.h"
#define BOARD_SIZE 9

typedef struct {
  cell_t grid[BOARD_SIZE][BOARD_SIZE];
} board_t;

void init_board(board_t * board);
void set_cell_val(board_t * board, int row, int col, int val);
int get_cell_val(board_t * board, int row, int col);