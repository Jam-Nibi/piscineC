int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int c;

	i = 0;
	c = ft_strlen(dest);
	while (i < size && src[i] != '\0')
	{
		dest[c] = src[i];
		i++;
		c++;
	}
	dest[c] = '\0';
	return (c);
}