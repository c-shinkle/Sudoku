CC = gcc
CFLAGS = -c -Wall -g
LDFLAGS = -Wall
SOURCES = board.c sudoku.c solver.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = ../sudoku

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
