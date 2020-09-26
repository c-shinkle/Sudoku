all: board_tests.c solver_tests.c test_runner.c ../unit_tests

../unit_tests: board_tests.o solver_tests.o
	gcc -Wall ../src/cell.o ../src/board.o ../src/solver.o \
	board_tests.o	solver_tests.o test_runner.c -lcunit -o ../unit_tests

board_tests.o:
	gcc -c -Wall board_tests.c -g -o board_tests.o

solver_tests.o:
	gcc -c -Wall solver_tests.c	-g -o solver_tests.o

clean:
	rm ../unit_tests *.o