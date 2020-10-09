OUTPUT = ../.bins
CC = gcc
CFLAGS = -c -Wall -g
LDFLAGS = -Wall
SOURCES = board.c sudoku.c solver.c
OBJECTS = $(SOURCES:%.c=$(OUTPUT)/%.o)
EXECUTABLE = ../sudoku

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

$(OUTPUT)/%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS)
