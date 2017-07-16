#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdio.h>
#include <stdlib.h>

#include "sudoku.h"

void fill(int *sudoku);
void randomize(int *sudoku);
void hideCells(int *sudoku);
void generate(int *sudoku);

#endif /* !GENERATOR_H_ */
