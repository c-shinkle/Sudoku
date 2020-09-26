#include "cell.h" 

void set_poss(cell_t* cell, char val) {
  if (1 <= val && val <= 9) {
    cell->poss |= 1 << (val-1);
  }
}
