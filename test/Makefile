all: board_tests.o solver_tests.o
	gcc -Wall -o ../unit_tests ../src/board.o ../src/cell.o ../src/solver.o board_tests.o \
	solver_tests.o test_runner.c -lcunit

board_tests.o:
	gcc -c -Wall board_tests.c ../src/board.o ../src/cell.o

solver_tests.o:
	gcc -c -Wall ../src/board.o ../src/cell.o ../src/solver.o solver_tests.c

clean:
	rm ../unit_tests *.o