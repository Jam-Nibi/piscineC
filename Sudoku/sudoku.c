#include "sudoku.h"

int at(int *sudoku, int i, int j)
{
  if (i < 0 || j < 0 || i >= 9 || j >= 9)
  {
    printf("Trying to access sudoku[%d; %d]\n", i, j);
    exit(1);
  }
  return sudoku[9*i+j];
}

void set(int *sudoku, int i, int j, int val)
{
  if (i < 0 || j < 0 || i >= 9 || j >= 9)
  {
    printf("Trying to set sudoku[%d; %d]\n", i, j);
    exit(1);
  }
  sudoku[9*i+j] = val;
}

int isValuePossible(int *sudoku, int i, int j, int val)
{
  for (int p = 0; p < 9; ++p)
  {
    if (p != i && at(sudoku, p, j) == val)
      return 0;
  }

  for (int p = 0; p < 9; ++p)
  {
    if (p != j && at(sudoku, i, p) == val)
      return 0;
  }

  int l = (i / 3) * 3;
  int c = (j / 3) * 3;

  for (int p = 0; p < 3; ++p)
  {
    for (int q = 0; q < 3; ++q)
    {
      if (l + p != i && c + q != j && at(sudoku, l + p, c + q) == val)
        return 0;
    }
  }

  return 1;
}

void sudoPrint(int *sudoku)
{
  for (int i = 0; i < 81; ++i)
    printf("%d", sudoku[i]);
}

void sudoPrettyPrint(int *sudoku)
{
  char buf[2];
  int d;

  for (int i = 0; i < 9; ++i)
  {
    if (i && !(i % 3))
    {
      for (int j = 0; j < 11; ++j)
        printf("%c", j == 3 || j == 7 ? '+' : '-');
      printf("\n");
    }

    for (int j = 0; j < 9; ++j)
    {
      d = at(sudoku, i, j);
      if (d < 0)
        sprintf(buf, "x");
      else if (d != 0)
        sprintf(buf, "%d", d);
      else
        sprintf(buf, " ");
      printf("%s%s", buf, j % 3 == 2 && j != 8 ? "|" : "");
    }

    printf("\n");
  }
}

void sudoRead(int *sudoku)
{
  for (int i = 0; i < 81; ++i)
  {
    int c = getchar();
    if (c == EOF || c == '\n')
    {
      printf("Error while reading sudoku: less than 81 digits\n");
      exit(1);
    }
    if (c < '0' || c > '9')
    {
      printf("Error while reading sudoku: invalid digit: '%c'\n", c);
      exit(1);
    }
    sudoku[i] = c - '0';
  }
}

void debugPrint(int *sudoku)
{
  char buf[2];
  int d;

  printf("   ");
  for (int i = 0; i < 9; ++i)
    printf("%d%s", i+1, !((i+1) % 3) ? " " : "");
  printf("\n\n");

  for (int i = 0; i < 9; ++i)
  {
    if (i && !(i % 3))
    {
      printf("   ");
      for (int j = 0; j < 11; ++j)
        printf("%c", j == 3 || j == 7 ? '+' : '-');
      printf("\n");
    }

    printf("%d  ", i+1);

    for (int j = 0; j < 9; ++j)
    {
      d = at(sudoku, i, j);
      if (d < 0)
        sprintf(buf, "x");
      else if (d != 0)
        sprintf(buf, "%d", d);
      else
        sprintf(buf, " ");
      printf("%s%s", buf, j % 3 == 2 && j != 8 ? "|" : "");
    }

    printf("\n");
  }
}
