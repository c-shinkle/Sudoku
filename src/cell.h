typedef struct {
  char value;
  short poss;
} cell_t;

typedef enum {
  ONE = 1,
  TWO = 2,
  THREE = 4,
  FOUR = 8,
  FIVE = 16,
  SIX = 32,
  SEVEN = 64,
  EIGHT = 128,
  NINE = 256,
} poss_t;

void set_poss(cell_t * cell, char poss);
short get_poss(cell_t * cell);
void set_poss_enum(cell_t * cell, poss_t poss);