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
		ft_putchar(str[i++]);
}

char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while(str[i] != '\0')
	{
		if (to_find[j] != str[i])
			j = 0;
		while(to_find[j] != '\0' && to_find[j] == str[i])
			j++;
		if (to_find[j] == '\0')
				return (str + i - j);
		i++;
	}
	 return (NULL);
}

int main(void)
{
	ft_putstr(ft_strstr("Salut comment ca va", "ca"));
	return 0;
}