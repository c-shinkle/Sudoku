typedef struct {
  char value;
  short poss;
} cell_t;

enum poss_t {
  ONE = 1,
  TWO = 2,
  THREE = 4,
  FOUR = 8,
  FIVE = 16,
  SIX = 32,
  SEVEN = 64,
  EIGHT = 128,
  NINE = 256,
};

void set_poss(cell_t * cell, enum poss_t poss);
short get_poss(cell_t * cell);