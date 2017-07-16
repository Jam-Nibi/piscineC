char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while(src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}


char *ft_strncat(char *dest, char *src, int nb)
{
	return (ft_strcnpy(dest + ft_strlen(dest), src, nb));
}