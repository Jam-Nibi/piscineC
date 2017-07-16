#include "generator.h"

void fillLine(int *sudoku, int l, int s)
{
  for (int i = 0; i < 9; ++i)
    set(sudoku, l, i, (s + i) % 9 + 1);
}

void fill(int *sudoku)
{
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
      fillLine(sudoku, i*3+j, 3 * j + i);
  }
}

void swapCells(int* sudoku, int i1, int j1, int i2, int j2)
{
  int t = at(sudoku, i1, j1);
  set(sudoku, i1, j1, at(sudoku, i2, j2));
  set(sudoku, i2, j2, t);
}

void swapCols(int *sudoku, int c1, int c2)
{
  for (int i = 0; i < 9; ++i)
    swapCells(sudoku, i, c1, i, c2);
}

void swapRows(int *sudoku, int r1, int r2)
{
  for (int i = 0; i < 9; ++i)
    swapCells(sudoku, r1, i, r2, i);
}

void swapColsBlock(int *sudoku, int c1, int c2)
{
  for (int i = 0; i < 3; ++i)
    swapCols(sudoku, 3 * c1 + i, 3 * c2 + i);
}

void swapRowsBlock(int *sudoku, int r1, int r2)
{
  for (int i = 0; i < 3; ++i)
    swapRows(sudoku, 3 * r1 + i, 3 * r2 + i);
}

void randomize(int *sudoku)
{
  for (int i = 0; i < 1000; ++i)
  {
    int a = (rand() % 3) * 3;
    switch (rand() % 4)
    {
    case 0: swapCols(sudoku, a + (rand() % 3), a + (rand() % 3)); break;
    case 1: swapRows(sudoku, a + (rand() % 3), a + (rand() % 3)); break;
    case 2: swapColsBlock(sudoku, rand() % 3, rand() % 3); break;
    case 3: swapRowsBlock(sudoku, rand() % 3, rand() % 3); break;
    default: break;
    }
  }
}

int isAmbigousToHide(int *sudoku, int i, int j)
{
  int n = 0;

  for (int p = 1; p <= 9; ++p)
  {
    if (isValuePossible(sudoku, i, j, p))
      ++n;
  }

  return n > 1;
}

int findCellToHide(int *sudoku, int *i, int *j)
{
  int si = *i;
  int sj = *j;

  do {
    *i = *i + 1;
    if (*i >= 9)
    {
      *i = 0;
      *j = *j + 1;
      if (*j >= 9)
        *j = 0;
    }

    if (at(sudoku, *i, *j) && !isAmbigousToHide(sudoku, *i, *j))
      return 1;

  } while (*i != si || *j != sj);

  return 0;
}

void hideCells(int *sudoku)
{
  int go = 1;
  int i, j;

  do {
    i = rand() % 9;
    j = rand() % 9;
    go = findCellToHide(sudoku, &i, &j);
    if (go)
      set(sudoku, i, j, 0);
  } while (go);
}

void generate(int *sudoku)
{
  fill(sudoku);
  randomize(sudoku);
  hideCells(sudoku);
}
