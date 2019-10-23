#include "libft.h"

void			ft_unsignedint(char *ss, va_list ap)
{
	int 			size;
	unsigned	long	long num;

	size = ft_parse_size(ss);
	if (size == h)
	{
		num = va_arg(ap, unsigned int);
		ft_flagunsignedint((short unsigned int)num, ss);
	}
	if (size == hh)
	{
		num = va_arg(ap, unsigned int);
		ft_flagunsignedint((unsigned char)num, ss);
	}
	if (size == l)
	{
		num = va_arg(ap, unsigned long int);
		ft_flagunsignedint((unsigned long int)num, ss);
	}
	if (size == ll)
	{
		num = va_arg(ap, unsigned long long int);
		ft_flagunsignedint((unsigned long long)num, ss);
	}
	if (size == 0)
	{
		num = va_arg(ap, unsigned int);
		ft_flagunsignedint((unsigned int)num, ss);
	}
}

void			ft_int(char *ss, va_list ap)
{
	int				size;
	long long int 	num;

	size = ft_parse_size(ss);
	if (size == h)
	{
		num = va_arg(ap, int);
		ft_flagint((short int)num, ss);
	}
	if (size == hh)
	{
		num = va_arg(ap, int);
		ft_flagint((signed char)num, ss);
	}
	if (size == l)
	{
		num = va_arg(ap, long int);
		ft_flagint((long int)num, ss);
	}
	if (size == ll)
	{
		num = va_arg(ap, long long int);
		ft_flagint(num, ss);
	}
	if (size == 0)
	{
		num = va_arg(ap, int);
		ft_flagint((int)num, ss);
	}
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
			ft_unsignedint(ss, ap);
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
