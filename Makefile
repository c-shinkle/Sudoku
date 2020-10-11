OUT_DIR = bin
SRC_DIR = src
TEST_DIR = test

CC = gcc
CFLAGS = -c -Wall -g
LFLAGS = -lcunit

SOURCES = board.c sudoku.c solver.c
SRC_OBJECTS = $(SOURCES:%.c=$(OUT_DIR)/%.o)
SRC_OBJ_NO_MAIN = $(filter-out $(OUT_DIR)/sudoku.o, $(SRC_OBJECTS))
SRC_EXEC = sudoku

TESTS = board_tests.c solver_tests.c test_runner.c
TEST_OBJECTS = $(TESTS:%.c=$(OUT_DIR)/%.o)
TEST_EXEC = unit_tests

EXECUTABLES = $(SRC_EXEC) $(TEST_EXEC)

all: $(EXECUTABLES)

$(SRC_EXEC): $(SRC_OBJECTS)
	$(CC) $^ -o $@

$(TEST_EXEC): $(SRC_OBJ_NO_MAIN) $(TEST_OBJECTS)
	$(CC) $(SRC_OBJ_NO_MAIN) $(TEST_OBJECTS) $(LFLAGS) -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(OUT_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -r $(EXECUTABLES) $(OUT_DIR)/

$(shell mkdir -p $(OUT_DIR)/)