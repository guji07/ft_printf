#include "ft_printf.h"

t_format		ft_parse_flag(int num, char *ss)
{
	int			i;
	int			j;
	t_format	form;

	j = 0;
	i = 0;
	while (j < 5)
		form.flag[++j] = 0;
	j = 0;
	while (ss[++i] && i <= num)
	{
		if (ss[i] == '-')
			((form).flag)[j++] = 1;
		if (ss[i] == '+')
			((form).flag)[j++] = 2;
		if (ss[i] == '0' && ss[i + 1] != '.')
			((form).flag)[j++] = 3;
		if (ss[i] == '#')
			((form).flag)[j++] = 4;
	}
	return (form);
}

int 		ft_conver_pos(char *s)
{
	int 	i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'c')
			return (i);
		if (s[i] == 's')
			return (i);
		if (s[i] == 'd' || s[i] == 'i')
			return (i);
		if (s[i] == 'p')
			return (i);
		if (s[i] == 'o')
			return (i);
		if (s[i] == 'u')
			return (i);
		if (s[i] == 'x')
			return (i);
		if (s[i] == 'X')
			return (i);
		if (s[i] == 'f')
			return (i);
		if (s[i] == '%')
			return (i);
	}
	return (0);
}

int 		ft_conver_name(char *s)
{
	int 	i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'c')
			return (10);
		if (s[i] == 's')
			return (20);
		if (s[i] == 'd' || s[i] == 'i')
			return (30);
		if (s[i] == 'p')
			return (40);
		if (s[i] == 'o')
			return (50);
		if (s[i] == 'u')
			return (60);
		if (s[i] == 'x')
			return (70);
		if (s[i] == 'X')
			return (80);
		if (s[i] == 'f')
			return (90);
		if (s[i] == '%')
			return (100);
	}
	return (0);
}