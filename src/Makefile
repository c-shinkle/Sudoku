CC = gcc
CFLAGS = -c -Wall -lm
LDFLAGS = 
SOURCEFILES = board.c cell.c sudoku.c solver.c
SOURCES = $(SOURCEFILES)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = ../sudoku

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -g -o $@

clean:
	rm -rf ../sudoku $(OBJECTS)
