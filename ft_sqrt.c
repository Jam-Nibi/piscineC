int ft_sqrt(int nb)
{
    int i;

    i = 1;
    while(i * i < nb)
        i++;
    if (i * i > nb)
        return(0);
    return (i);
}