int ft_iterative_factorial(int nb)
{
	int i;

	i = 1;
	if (nb < 0 || nb > 12)
		return 0;
	while(nb)
	{
		i *= nb;
		nb--;
	}
	return (i);
}