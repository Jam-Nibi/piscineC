char *ft_strdup(char *src)
{
	int size;
	char *dest;

	size = 0;
	while(src[size])
		size++;
	dest = (char*)malloc(sizeof (char) * (size + 1));
	ft_strcpy(dest, src);
	return (dest);
}