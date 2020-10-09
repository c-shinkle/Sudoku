OUTPUT = ../.bins
CC = gcc
CFLAGS = -c -Wall -g
LDFLAGS = -Wall -lcunit
TESTS = board_tests.c solver_tests.c test_runner.c
TEST_OBJECTS = $(TESTS:%.c=$(OUTPUT)/%.o)
SRC_OBJECTS = $(OUTPUT)/board.o $(OUTPUT)/solver.o
EXECUTABLE = ../unit_tests

all: $(TESTS) $(EXECUTABLE)

$(EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(SRC_OBJECTS) $^ $(LDFLAGS) -o $@

$(OUTPUT)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) $(TEST_OBJECTS)
	