char *ft_strncat(char *dest, char *src)
{
	return (ft_strcnpy(dest + ft_strlen(dest), src));
}