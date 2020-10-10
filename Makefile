OUT_DIR = .bins/
SRC_DIR = src/
TEST_DIR = test/

CC = gcc
CFLAGS = -c -Wall -g
LDFLAGS = -Wall -lcunit

SOURCES = board.c sudoku.c solver.c
SRC_OBJECTS = $(SOURCES:%.c=$(OUT_DIR)%.o)
SRC_EXEC = sudoku

TESTS = board_tests.c solver_tests.c test_runner.c
TEST_OBJECTS = $(TESTS:%.c=$(OUT_DIR)%.o)
TEST_EXEC = unit_tests

EXECUTABLES = $(SRC_EXEC) $(TEST_EXEC)

all: $(EXECUTABLES)

$(SRC_EXEC): $(SRC_OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

$(TEST_EXEC): $(TEST_OBJECTS)
	$(CC) $(filter-out $(OUT_DIR)sudoku.o, $(SRC_OBJECTS)) $^ $(LDFLAGS) -o $@

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(OUT_DIR)%.o: $(TEST_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -r $(EXECUTABLES) $(OUT_DIR)

$(shell mkdir -p $(OUT_DIR))