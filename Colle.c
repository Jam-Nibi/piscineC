#include <unistd.h>

void ft_putchar(char c)
{
	write(1 , &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		ft_putchar(str[i++]);
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

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s2[i] - s1[i]);
}

int  ft_atoi(char *str)
{
	int i;
	int out;
	int signe;

	signe = 1;
	i = 0;
	out = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if(str[i] == '+' || str[i] == '-')
		signe = str[i++] == '-' ? -1 : 1;
	while(str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0'
;		i++;
	}
	return (out * signe);
} 

void colle_steps(int steps, char step_one, char step_two, char step_three)
{
	ft_putchar(step_one);
	while((steps - 1) > 1)
	{
		ft_putchar(step_two);
		steps--;
	}
	if (steps > 1)
		ft_putchar(step_three);
	ft_putchar('\n');
}

void colle00(int x, int y)
{
	if (x > 0 && y > 0)
	{
		colle_steps(x, '0', '-', '0');
		y--;
		while(y > 1)
		{
			colle_steps(x, '|', ' ', '|');
			y--;
		}
		if (y == 1)
			colle_steps(x, '0', '-', '0');
	}
}

void colle01(int x, int y)
{
	if (x > 0 && y > 0)
	{
		colle_steps(x, '/', '*', 92);
		y--;
		while(y > 1)
		{
			colle_steps(x, '*', ' ', '*');
			y--;
		}
		if (y == 1)
			colle_steps(x, 92, '*', '/');
	}
}

void colle02(int x, int y)
{
	if (x > 0 && y > 0)
	{
		colle_steps(x, 'A', 'B', 'C');
		y--;
		while(y > 1)
		{
			colle_steps(x, 'B', ' ', 'B');
			y--;
		}
		if (y == 1)
			colle_steps(x, 'A', 'B', 'C');
	}
}

void colle03(int x, int y)
{
	if (x > 0 && y > 0)
	{
		colle_steps(x, 'A', 'B', 'C');
		y--;
		while(y > 1)
		{
			colle_steps(x, 'B', ' ', 'B');
			y--;
		}
		if (y == 1)
			colle_steps(x, 'A', 'B', 'C');
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	int x;
	int y;
	
	if (argc < 4)
	{
		ft_putstr("Rajoutez des arguments");
		return (0);
	}
	if (argc > 4)
	{
		ft_putstr("Vous avez mis trop d'arguments");
		return (0);
	}
	else if (argc == 4)
	{
		x = ft_atoi(argv[2]);
		y = ft_atoi(argv[3]);
		if (ft_strcmp(argv[1], "colle00") == 0)
			colle00(x, y);
		if (ft_strcmp(argv[1], "colle00") == 0)
			colle00(x, y);
		if (ft_strcmp(argv[1], "colle01") == 0)
			colle01(x, y);
		if (ft_strcmp(argv[1], "colle02") == 0)
			colle02(x, y);
		if (ft_strcmp(argv[1], "colle03") == 0)
			colle03(x, y);
	}
	else
	{
		ft_putstr("Erreur: je ne trouve pas la colle!");
		return (0);
	}
	
}