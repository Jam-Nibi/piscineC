char *ft_strcpy(char *dest, char *src)
{
	int i;
 
	i = -1;
	while(src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}