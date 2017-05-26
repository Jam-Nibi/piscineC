#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		ft_putchar(str[i++])
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

int main(void)
{
	char src[6];
	src[0] = 's';
	src[1] = 'a';
	src[2] = 'l';
	src[3] = 'u';
	src[4] = 't';
	src[5] = '\0';

	char dest[7];
	src[0] = 's';
	src[1] = 'a';
	src[2] = 'l';
	src[3] = 'u';
	src[4] = 't';
	src[5] = 'e';
	src[6] = '\0';

	ft_strcpy(dest, src);

	ft_putstr(dest);
	return 0;
}