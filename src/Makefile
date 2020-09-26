CC = gcc
CFLAGS = -c -Wall -g
LDFLAGS = -Wall -g
SOURCES = board.c cell.c sudoku.c solver.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = ../sudoku

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -g -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
