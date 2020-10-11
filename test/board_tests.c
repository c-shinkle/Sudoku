#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/board.h"

void init_board_test()
{
  board_t board;
  int i, j;

  init_board(&board);
  for (i = 0; i < BOARD_SIZE; i++)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      if (board.grid[i][j].value)
      {
        CU_FAIL("All of board.grid's values weren't initialized to 0");
      }
    }
  }
  CU_PASS("All of board.grid's values were initialized to 0");
}

void print_row_test()
{
  board_t board;
  char buffer[ROW_LENGTH + 1];
  uint8_t i;
  init_board(&board);
  for (i = 0; i < BOARD_SIZE; i++)
  {
    board.grid[0][i].value = i + 1;
  }
  const char *result = print_row(&board, buffer, 0);
  CU_ASSERT_STRING_EQUAL(result, "|123|456|789|\n");
}

void print_blank_row_test()
{
  CU_ASSERT_STRING_EQUAL(print_blank_row(), "-------------\n");
}

void print_board_test0()
{
  board_t board;
  init_board(&board);
  char buffer[ROW_LENGTH * COL_LENGTH + 1];
  char *expected_board_printout =
      "-------------\n"
      "|000|000|000|\n"
      "|000|000|000|\n"
      "|000|000|000|\n"
      "-------------\n"
      "|000|000|000|\n"
      "|000|000|000|\n"
      "|000|000|000|\n"
      "-------------\n"
      "|000|000|000|\n"
      "|000|000|000|\n"
      "|000|000|000|\n"
      "-------------\n";

  char *actual_board_printout = print_board(&board, buffer);

  CU_ASSERT_STRING_EQUAL(actual_board_printout, expected_board_printout);
}

void print_board_test1()
{
  board_t board;
  init_board(&board);
  char buffer[ROW_LENGTH * COL_LENGTH + 1];

  uint8_t i;
  for (i = 0; i < BOARD_SIZE; i++)
  {
    board.grid[i][i].value = i + 1;
  }
  const char *expected_printout =
      "-------------\n"
      "|100|000|000|\n"
      "|020|000|000|\n"
      "|003|000|000|\n"
      "-------------\n"
      "|000|400|000|\n"
      "|000|050|000|\n"
      "|000|006|000|\n"
      "-------------\n"
      "|000|000|700|\n"
      "|000|000|080|\n"
      "|000|000|009|\n"
      "-------------\n";

  const char *actual_printout = print_board(&board, buffer);

  CU_ASSERT_STRING_EQUAL(actual_printout, expected_printout);
}

void set_board_string_test()
{
  board_t board;
  init_board(&board);
  char buffer[ROW_LENGTH * COL_LENGTH + 1];
  const char *board_string =
      "111111111"
      "222222222"
      "333333333"
      "444444444"
      "555555555"
      "666666666"
      "777777777"
      "888888888"
      "999999999";
  set_board_string(&board, board_string);
  const char *expected_printout =
      "-------------\n"
      "|111|111|111|\n"
      "|222|222|222|\n"
      "|333|333|333|\n"
      "-------------\n"
      "|444|444|444|\n"
      "|555|555|555|\n"
      "|666|666|666|\n"
      "-------------\n"
      "|777|777|777|\n"
      "|888|888|888|\n"
      "|999|999|999|\n"
      "-------------\n";

  const char *actual_printout = print_board(&board, buffer);

  CU_ASSERT_STRING_EQUAL(actual_printout, expected_printout);
}

void should_return_error_when_string_is_not_correct_length()
{
  board_t board;
  init_board(&board);
  char *bad_string = "This is a bad string\n";

  uint8_t actual_error_code = set_board_string(&board, bad_string);

  CU_ASSERT_EQUAL(actual_error_code, 1);
}

void set_poss_test()
{
  cell_t cell;
  cell.poss = 0b111111111;

  elim_poss(&cell, 1);
  elim_poss(&cell, 2);
  elim_poss(&cell, 3);

  uint16_t actual_poss = cell.poss;
  CU_ASSERT_EQUAL(actual_poss, 0b111111000);
}
