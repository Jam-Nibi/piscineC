int ft_iterative_power(int nb, int power)
{
	int i;

	i = 1;
	if(power == 0)
		return (1);
	while(power > 0)
	{
		i *= nb;
		power--;
	}
	return (i);
}