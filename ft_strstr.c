char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		if (to_find[j] != str[i])
			j = 0;
		while(to_find[j] != '\0' && to_find[j] == str[i])
			j++;
		if (to_find[j] == '\0')
				return (str + i - j);
		i++;
	}
	 return (NULL);
}