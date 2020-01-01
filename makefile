CC = gcc
OBJS = main.o Game.o MainAux.o Parser.o Solver.o
EXEC = sudoku
COMP_FLAG = -ansi -Wall -Wextra -Werror -pedantic-errors

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@
main.o: main.c Game.h Parser.h MainAux.h
	$(CC) $(COMP_FLAG) -c $*.c
MainAux.o: MainAux.c Solver.h Game.h
	$(CC) $(COMP_FLAG) -c $*.c
Parser.o: Parser.c Parser.h
	$(CC) $(COMP_FLAG) -c $*.c
Solver.o: Solver.c MainAux.h Game.h
	$(CC) $(COMP_FLAG) -c $*.c
clean:
	rm -f $(OBJS) $(EXEC)
