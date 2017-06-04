int main(int argc, char const *argv[])
{
	int i;

	i = 1;
	while(i < argc)
		ft_putstr(argv[i++]);
	return 0;
}