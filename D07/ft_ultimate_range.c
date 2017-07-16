#include <stdlib.h>
#include <stdio.h>

int 	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int i;

	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	while (i + min < max)
	{
		tab[i] = i + min;
		i++;
	}
	*range = tab;
	return (max - min);
}

int		main(void)
{
	int *a;
	int i;

	ft_ultimate_range(&a, 5, 50);
	i = 0;
	while (i < 50 - 5)
	{
		printf("%d\n", a[i++]);
	}
}