#include "solver.h"

int findValue(int *sudoku, int i, int j)
{
  int n = 0;

  for (int p = 0; p <= 9; ++p)
  {
    if (isValuePossible(sudoku, i, j, p))
    {
      if (n)
        return 0;
      n = p;
    }
  }

  return !n ? -1 : n;
}

int solved(int *sudoku)
{
  for (int i = 0; i < 81; ++i)
  {
    if (sudoku[i] <= 0)
      return 0;
  }

  return 1;
}

int solve(int *sudoku)
{
  int i, j, n;

  while (!solved(sudoku))
  {
    i = j = n = 0;
    do
    {
      if (!at(sudoku, i, j))
        n = findValue(sudoku, i, j);

      if (n == -1)
        return 0;

      if (!n)
      {
        ++i;
        if (i >= 9)
        {
          i = 0;
          ++j;
          if (j >= 9)
            j = 0;
        }
      }

    } while (!n && (i || j));

    if (!n)
      return 0;

    set(sudoku, i, j, n);
  }

  return 1;
}
