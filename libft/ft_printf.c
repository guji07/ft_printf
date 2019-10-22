#include "libft.h"

void			ft_int(char *ss, va_list ap)
{
	int 	size;

	size = ft_parse_size(ss);
	if (size == 0 || size == 1 || size == 2)
		ft_flagint(va_arg(ap, int), ss);
	if (size == 3)
		ft_flagint(va_arg(ap, long int), ss);
	if (size == 4)
		ft_flagint(va_arg(ap, long long int), ss);
}

int				ft_format(char *ss, va_list ap)
{
	int 	type;

	if ((type = ft_parse_name(ss)))
	{
		if (type >= 10 && type < 20)
			ft_flagchar(ss, va_arg(ap, int));
		if (type >= 20 && type < 30)
			ft_flagstr(va_arg(ap, char*), ss);
		if (type >= 30 && type < 40)
			ft_int(ss, ap);
		if (type >= 40 && type < 50)
			return (1);
		if (type == 100)
			ft_flagpercent(ss);
	}
	return (ft_len_to_type(ss));
}

int				ft_printf(char* str, ...)
{
	int			i;
	va_list		ap;

	if (!str)
		return (0);
	kolvo = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_write(*(str + i));
		else
			i = i + ft_format(str + i, ap);
		i++;
	}
	return (kolvo);
}
