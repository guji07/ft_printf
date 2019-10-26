#include "libft.h"

void				ft_octetleft(char *str, t_format form)
{
	int 	width;
	int 	max;

	width = 0;
	if (HASHTAG)
		width++;
	max = ft_max(form.precision, ft_strlen(str));
	if (form.width < max)
		form.width = max;
	while (width++ < form.precision - (int)ft_strlen(str) + PLUS)
		ft_write('0');
	if (HASHTAG)
		ft_write('0');
	ft_putstr(str);
	while ((width < form.width - (int)ft_strlen(str) + !SPACE))
	{
		ft_write(' ');
		width++;
	}
}

void				ft_octetright(char *str, t_format form)
{
	int 	width;
	int 	max;
	int 	len;

	width = 0;
	if (HASHTAG && (!ft_strequ("0", str)))
		width++;
	len = ft_strlen(str);
	if (!form.precision && str[0] == '0')
		len = 0;
	max = ft_max(form.precision, len);
	if (form.width < max)
		form.width = max;
	while ((width < form.width - max - PLUS) && !(ZERO && form.precision == -1))
	{
		ft_write(' ');
		width++;
	}
	if (HASHTAG && (!ft_strequ("0", str)))
		ft_write('0');
	if (form.precision >= form.width && (PLUS))
		width--;
	while ((width++ < form.width - len) && (form.precision > len || (ZERO && form.precision == -1)))
		ft_write('0');
	if (form.precision || str[0] != '0')
		ft_putstr(str);
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
	if (!MINUS)
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
		num = va_arg(ap, int);
		ft_flagoctet((int)num, ss);
	}
}