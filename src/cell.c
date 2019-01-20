#include "cell.h" 

void set_poss(cell_t * cell, enum poss_t poss) {
  cell->poss |= poss;
}

short get_poss(cell_t * cell) {
  return cell->poss;
}
