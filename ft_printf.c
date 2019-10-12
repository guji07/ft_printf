#include "ft_printf.h"
#include "libft/libft.h"
/*
 * void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
 */

int				ft_format(char *ss, va_list ap)
{
	int 	type;

	if ((type = ft_parse_name(ss)))
	{
		if (type >= 10 && type < 20)
			ft_putchar(va_arg(ap, int));
		if (type >= 20 && type < 30)
			ft_putstr(va_arg(ap, char*));
		if (type >= 30 && type < 40)
			ft_flagint(va_arg(ap, int), ss);
		if (type >= 40 && type < 50)
			return (1);
		if (type == 100)
			write(1, "%", 1);
	}
	return (ft_len_to_type(ss));
}

int				ft_printf(char* str, ...)
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
