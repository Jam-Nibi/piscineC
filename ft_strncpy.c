#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while(i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while(i < n)
		dest[i++] = '\0';
	return(dest);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}