char *ft_strncat(char *dest, char *src, int nb)
{
	return (ft_strcnpy(dest + ft_strlen(dest), src, nb));
}