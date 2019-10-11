#include "ft_printf.h"
#include "libft/libft.h"
/*
 * void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
 */

int 		ft_pos_conver(char *s)
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

int 	ft_parse_flag(char *ss, int num)
{
	int 	i;

	i = 0;
	while (ss[++i] && i <= num)
	{
		if (ss[i] == '-')
			return (1);
		if (ss[i] == '0' && ss[i + 1] != '.')
			return (2);
		if (ss[i] == '+')
			return (3);
		if (ss[i] == '#')
			return (4);
	}
	return (0);
}

int 		ft_first_conver(char *s)
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

int			ft_format(char *ss, va_list ap, t_format form)
{
	int 	type;

	if ((type = ft_first_conver(ss)))
	{
		if (type >= 10 && type < 20)
			ft_putchar(va_arg(ap, int));
		if (type >= 20 && type < 30)
			ft_putstr(va_arg(ap, char*));
		if (type >= 30 && type < 40)
			ft_putnbr(va_arg(ap, int));
		if (type >= 40 && type < 50)
			return (1);
		if (type == 100)
			write(1, "%", 1);
	}
	return (1);
}

//parses chars between % and type to get flags, width

int 	ft_get_all(char *ss, va_list ap)
{
	t_format	form;

	form.flag = ft_parse_flag(ss, ft_pos_conver(ss));
	ft_format(ss, ap, form);
	return (/*form.width*/ + 1);
}

int 	ft_printf(char* str, ...)
{
	int			i;
	va_list		ap;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(1, str + i, 1);
		else
			i = i + ft_get_all(str + i, ap);
		i++;
	}
	return (0);
}
