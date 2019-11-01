#include "libft.h"

void				ft_octetleft(char *str, t_format form)
{
	int 	width;
	int 	max;
	int 	len;

	len = ft_strlen(str);
	width = 0;
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision < len)
		width++;
	max = ft_max(form.precision, len);
	if (form.width < max)
		form.width = max;
	while (width++ < form.precision - len + PLUS)
		ft_write("0", 1);
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision <= len)
		ft_write("0", 1);
	if (HASHTAG && form.precision == -1 && (ft_strequ("0", str)))
		width--;
	ft_putstr(str);
	width--;
	while ((width < form.width - len))
	{
		ft_write(" ", 1);
		width++;
	}
}

void				ft_octetright(char *str, t_format form)
{
	int 	width;
	int 	max;
	int 	len;

	len = ft_strlen(str);
	width = 0;
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision < len)
		width++;
	if (!form.precision && str[0] == '0')
		len = 0;
	max = ft_max(form.precision, len);
	if (form.width < max)
		form.width = max;
	while ((width < form.width - max - PLUS) && !(ZERO && form.precision == -1))
	{
		ft_write(" ", 1);
		width++;
	}
	if (form.precision >= form.width && (PLUS))
		width--;
	while ((width++ < form.width - len) && (form.precision > len || (ZERO && form.precision == -1)))
		ft_write("0", 1);
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision <= len)
		ft_write("0", 1);
	if (form.precision || str[0] != '0')
		ft_putstr(str);
}

void				ft_writezeros(char *str, t_format form)
{
	int 	i;

	i = 0;
	if (!MINUS)
	{
		while (i < form.width - ft_max(form.precision, str[0] == '0' ? 0 : ft_strlen(str)))
		{
			ft_write(" ", 1);
			i++;
		}
		if (HASHTAG)
			ft_write("0", 1);
		else if (form.precision != 0)
			ft_write(" ", 1);
	}
	else
	{
		if (HASHTAG)
			ft_write("0", 1);
		else if (form.width)
			ft_write(" ", 1);
		while (i < form.width - ft_max(form.precision, ft_strlen(str)))
		{
			ft_write(" ", 1);
			i++;
		}
	}
}

void				ft_flagoctet(unsigned long long num, char *ss)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(40);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabaseunsigned(num, str, 8);
	if (str[0] == '0' && !form.precision)
		ft_writezeros(str, form);
	else if (!MINUS)
		ft_octetright(str, form);
	else
		ft_octetleft(str, form);
	free(str);
	free(form.flag);
}

void				ft_octet(char *ss, va_list ap)
{
	int							size;
	unsigned	long	long  	num;

	size = ft_parse_size(ss);
	if (size == h)
	{
		num = va_arg(ap, unsigned int);
		ft_flagoctet((short unsigned)num, ss);
	}
	else if (size == hh)
	{
		num = va_arg(ap, unsigned int);
		ft_flagoctet((unsigned char)num, ss);
	}
	else if (size == l)
	{
		num = va_arg(ap, unsigned long int);
		ft_flagoctet((unsigned long int)num, ss);
	}
	else if (size == ll)
	{
		num = va_arg(ap, unsigned long long int);
		ft_flagoctet(num, ss);
	}
	else if (size == 0)
	{
		num = va_arg(ap, unsigned int);
		ft_flagoctet((unsigned int)num, ss);
	}
}
