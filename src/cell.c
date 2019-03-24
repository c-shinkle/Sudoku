#include "cell.h" 

void set_poss(cell_t * cell, char val) {
  switch(val) {
    case 1: set_poss_enum(cell, ONE); break;
    case 2: set_poss_enum(cell, TWO); break;
    case 3: set_poss_enum(cell, THREE); break;
    case 4: set_poss_enum(cell, FOUR); break;
    case 5: set_poss_enum(cell, FIVE); break;
    case 6: set_poss_enum(cell, SIX); break;
    case 7: set_poss_enum(cell, SEVEN); break;
    case 8: set_poss_enum(cell, EIGHT); break;
    case 9: set_poss_enum(cell, NINE); break;

    default: break;
  }
}

short get_poss(cell_t * cell) {
  return cell->poss;
}

void set_poss_enum(cell_t * cell, poss_t poss) {
  cell->poss |= poss;
}