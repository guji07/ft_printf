#include "libft.h"

int				ft_format(char *ss, va_list ap)
{
	int 	type;

	if ((type = ft_parse_name(ss)))
	{
		if (type == 10)
			ft_flagchar(ss, va_arg(ap, int));
		else if (type == 20)
			ft_flagstr(va_arg(ap, char*), ss);
		else if (type == 30)
			ft_int(ss, ap);
		else if (type == 40)
			ft_unsignedint(ss, ap);
		else if (type == 50)
			ft_octet(ss, ap);
		else if (type == 70)
			ft_xtet(ss, ap, 1);
		else if (type == 60)
            ft_xtet(ss, ap, 3);
		else if (type == 80)
			ft_xtet(ss, ap, 2);
		else if (type == 90)
			return (0);
		else if (type == 100)
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
