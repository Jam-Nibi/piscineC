#include "sudoku.h"

int		main(int argc, char **argv)
{
	if (check_grille(argv, argc))
	{
		if (sudoku(argv, 9))
			affichage(argv);
		else
		{
			ft_putstr("Erreur");
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("Erreur");
		ft_putchar('\n');
	}
	return (0);
}