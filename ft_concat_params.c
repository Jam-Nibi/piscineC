#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1 , &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
}

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

char *ft_strcat(char *dest, char *src)
{
	return(ft_strcpy(dest + ft_strlen(dest), src));
}

char *ft_concat_params(int argc, char **argv)
{
	int i;
	int c;
	char *t;

	i = 1;
	c = 0;
	while(i < argc)
		c += ft_strlen(argv[i++]) + 1;
	t = (char *)malloc(sizeof(char) * c + 1);
	i = 1;
	while(i < argc)
	{
		ft_strcat(t, argv[i++]);
		ft_strcat(t, "\n");
	}
	return(t);
}

int main(int argc, char **argv)
{
	ft_putstr(ft_concat_params(argc, argv));
	return 0;
}