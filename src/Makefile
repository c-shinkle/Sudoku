CC = gcc
CFLAGS = -c -Wall
LDFLAGS = 
SOURCES = board.c cell.c sudoku.c solver.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = ../sudoku

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -g -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
