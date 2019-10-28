#include "libft.h"

void				ft_xtetleft(char *str, t_format form, int mode)
{
	int 	precision;
	int 	len;
	int 	width;

	len = ft_strlen(str);
	precision = ft_max(form.precision, len);
	width = form.width - precision;
	if (HASHTAG)
	{
		ft_putstr(mode == 2 ? "0X" : "0x");
		width -= 2;
	}
	while (precision - len)
	{
		precision--;
		ft_write("0", 1);
	}
	ft_putstr(str);
	while (width > 0)
	{
		ft_write(" ", 1);
		width--;
	}
}

void				ft_xtetright(char *str, t_format form, int mode)
{
	int 	width;
	int 	precision;
	int 	len;

	len = ft_strlen(str);
	precision = ft_max(form.precision, len);
	width = form.width - precision;
	if (HASHTAG)
		width -= 2;
	while (width > 0)
	{
		ft_write(" ", 1);
		width--;
	}
	if (HASHTAG)
		ft_putstr(mode == 2 ? "0X" : "0x");
	while (precision - len)
	{
		precision--;
		ft_write("0", 1);
	}
	if (mode == 2)
		ft_putupstr(str);
	else
		ft_putstr(str);
}

void		ft_flagxtet(unsigned long long num, char *ss, int mode)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(21);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabaseunsigned(num, str, 16);
	if (MINUS)
		ft_xtetleft(str, form, mode);
	else
		ft_xtetright(str, form, mode);
	free(str);
	free(form.flag);
}

void		ft_xtet(char *ss, va_list ap, int mode)
{
	int				size;
	unsigned long long int 	num;

	size = ft_parse_size(ss);
	if (size == h)
	{
		num = va_arg(ap, unsigned int);
		ft_flagxtet((unsigned short int)num, ss, mode);
	}
	else if (size == hh)
	{
		num = va_arg(ap, unsigned int);
		ft_flagxtet((unsigned char)num, ss, mode);
	}
	else if (size == l)
	{
		num = va_arg(ap, unsigned long int);
		ft_flagxtet((unsigned long int)num, ss, mode);
	}
	else if (size == ll || ft_parse_name(ss) == 60)
	{
		num = va_arg(ap, unsigned long long int);
		ft_flagxtet(num, ss, mode);
	}
	else if (size == 0)
	{
		num = va_arg(ap, unsigned int);
		ft_flagxtet(num, ss, mode);
	}
}