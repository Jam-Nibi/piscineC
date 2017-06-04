int  ft_atoi(char *str)
{
	int i;
	int out;
	int signe;

	signe = 1;
	i = 0;
	out = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if(str[i] == '+' || str[i] == '-')
		signe = str[i++] == '-' ? -1 : 1;
	while(str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0'
;		i++;
	}
	return (out * signe);
}