#include <unistd.h>

char *ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;
 
	i = -1;
	while(src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

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

struct sort_params
{
	char str[1000];
	struct sort_params *prev;
	struct sort_params *next;
};

int		main(int argc, char **argv)
{
	int i;


	return (0);
}