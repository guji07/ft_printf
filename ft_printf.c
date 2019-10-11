#include "ft_printf.h"
#include "libft/libft.h"
/*
 * void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
 */



int			ft_get_flag(char *s)
{
	if (s[1] == 'c')
		return (10);
	if (s[1] == 'i' || s[1] == 'd')
		return (20);
	if (s[1] == 's')
		return (30);
	if (s[1] == 'f')
		return (40);
	if (s[1] == '%')
		return (90);
	return (0);
}

int			ft_format(char *ss, va_list arg)
{
	int 	flag;

	flag = ft_get_flag(ss);
	if (flag >= 10 && flag < 20)
		ft_putchar(va_arg(arg, int));
	if (flag >=20 && flag < 30)
		ft_putnbr(va_arg(arg, int));
	if (flag >= 30 && flag < 40)
		ft_putstr(va_arg(arg, char*));
	if (flag >= 40 && flag < 50)
		return (1);
	if (flag == 90)
		write(1,"%",1);
	return (1);
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
			i = i + ft_format(str + i, ap);
		i++;
	}
	return (0);
}
