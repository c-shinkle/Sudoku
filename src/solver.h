#pragma once
#include "board.h"
#include <stdint.h>

void naive_solver(board_t *board);
void populate_possible_values(board_t *board, uint8_t row, uint8_t col);