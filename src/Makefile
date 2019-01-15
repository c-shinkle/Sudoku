CC = gcc
CFLAGS = -c -Wall
LDFLAGS = 
SOURCEFILES = board.c sudoku.c
SOURCES = $(SOURCEFILES)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = sudoku

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf sudoku $(OBJECTS)
