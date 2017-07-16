CC=clang
LD=gcc
CFLAGS=-W -Wall -Werror -Wextra -ansi -pedantic -std=c99 -O3
LDFLAGS=
SRC=sudoku.c generator.c solver.c main.c
EXEC=sudoku

OBJ=$(SRC:.c=.o)

all: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(EXEC) -fPIC

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *{.o,~}

mrproper: clean
	rm $(EXEC)
