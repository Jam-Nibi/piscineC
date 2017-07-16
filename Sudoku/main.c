#include <stdio.h>
#include <time.h>
#include <string.h>

#include "sudoku.h"
#include "generator.h"
#include "solver.h"

void usage(const char *prgm)
{
  printf("usage: %s type [--pretty] [--help]\n", prgm);
  printf("type:   print | generate | solve\n");
  printf("pretty: pretty printing\n");
  printf("help:   show this help\n");
}

void print(int *sudoku, int pretty)
{
  if (pretty)
    sudoPrettyPrint(sudoku);
  else
    sudoPrint(sudoku);
}

void generator(int debug, int pretty)
{
  int sudoku[81];

  if (debug)
    printf("Starting generator\n");

  generate(sudoku);
  print(sudoku, pretty);
}

void solver(int debug, int pretty)
{
  int sudoku[81];

  sudoRead(sudoku);

  if (debug)
  {
    printf("Starting solver\n");
    printf("Solving:\n\n");
    print(sudoku, pretty);
    printf("\n");
  }

  int result = solve(sudoku);
  if (debug)
    printf("%s\n\n", result ? "Solved!" : "Cannot solve this sudoku... :(");

  print(sudoku, pretty);
}

int main(int argc, char **argv)
{
  srand(time(NULL));

  int type = 0;
  int help = 0;
  int pretty = 0;
  int debug = 0;
  char file[256] = { 0 };

  for (int i = 1; i < argc; ++i)
  {
    if (!strcmp(argv[i], "print"))
      type = 1;
    else if (!strcmp(argv[i], "generator"))
      type = 2;
    else if (!strcmp(argv[i], "solver"))
      type = 3;
    else if (!strcmp(argv[i], "--help"))
      help = 1;
    else if (!strcmp(argv[i], "--pretty"))
      pretty = 1;
    else if (!strcmp(argv[i], "--debug"))
      debug = 1;
    else if (!strcmp(argv[i], "--file"))
    {
      ++i;
      if (i == argc)
      {
        printf("--file: missing parameter");
        return 1;

        strncpy(file, argv[i], 256);
      }
    }
    else
      printf("Unknown option: %s\n\n", argv[i]);
  }

  if (help || !type)
  {
    usage(argv[0]);
    return 0;
  }

  if (type == 1)
  {
    int sudoku[81];
    sudoRead(sudoku);
    print(sudoku, pretty);
  }
  else if (type == 2)
    generator(debug, pretty);
  else
    solver(debug, pretty);

  return 0;
}
