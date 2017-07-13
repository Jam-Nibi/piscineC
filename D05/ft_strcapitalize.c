char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 0;
	while(str[i])
	{
		if ((str[i] >= 1 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) 
		 || (str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 127))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[++i] -= 32;
		}
		i++;
	}
	return (str);
}