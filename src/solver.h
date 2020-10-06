#pragma once
#include "board.h"
#include <stdint.h>

uint8_t naive_solver(board_t *board);
void populate_possible_values(board_t *board, uint8_t row, uint8_t col);
uint8_t find_possibility(board_t *board_t, uint8_t row, uint8_t col);
void update_influenced_cells(board_t* board, uint8_t row, uint8_t col);