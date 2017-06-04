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