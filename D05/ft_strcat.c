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
	ft_strcpy(dest + (dest, src));
	return(dest);
}

int main(int argc, char const *argv[])
{
	ft_putstr(ft_strcat("Salut comment", "ca va"));
	return 0;
}