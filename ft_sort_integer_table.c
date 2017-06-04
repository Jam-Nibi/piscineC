void ft_sort_integer_table(int *tab, int size)
{
	int i;
	int nb;

	i = 0;
	while(i < size - 1)
	{
		if(tab[i] > tab[i + 1])
		{
			nb = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = nb;
			i = 0;
		}
		else
			i++;
	}
}