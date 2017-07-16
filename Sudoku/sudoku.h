#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <stdio.h>
#include <stdlib.h>

int at(int *sudoku, int i, int j);
void set(int *sudoku, int i, int j, int val);
int isValuePossible(int *sudoku, int i, int j, int val);
void sudoPrint(int *sudoku);
void sudoPrettyPrint(int *sudoku);
void sudoRead(int *sudoku);

void debugPrint(int *sudoku);

#endif /* !SUDOKU_H_ */
