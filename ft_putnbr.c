#ifndef linux
#include <Windows.h>
#else 
#include <unistd.h>
#endif
#include <stdio.h>

#ifndef linux
void write(int i, char * c, int is) {
	printf("%c", c[0]);
}
#endif

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    int a;
    int c;

    if ((a = nb < 0 ? -1 : 1) == -1)
        ft_putchar('-');
    c = nb;
    while (c /= 10)
        a *= 10;
    while (a)
    {
        c = nb / a;
        ft_putchar(c + 48);
        nb = nb - c*a;
        a = a / 10;
    }
}

/*void   ft_putnbr(int nb)
{
    if (nb < 0)
    {
        nb = -nb;
        ft_putchar('-');
    }
    if (nb > 9)
        ft_putnbr(nb / 10);
   ft_putchar(nb % 10 + '0');
}
*/

int main(int argc, char const *argv[])
{
	ft_putnbr(-2);
	return 0;
}