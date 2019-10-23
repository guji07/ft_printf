#include "libft.h"

void		ft_int(char *ss, va_list ap)
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

void		ft_intleft(long long num, t_format form)
{
	int 	width;
	int 	max;

	max = ft_max(form.precision, ft_intlen(num));
	width = 0;
	if (form.width < max)
		form.width = max;
	if (SPACE && !PLUS && num >= 0)
		ft_write(' ');
	if (PLUS || num <= 0)
	{
		ft_write(num >= 0  ? '+' : '-');
		width++;
	}
	while (width++ < form.precision - ft_intlen(num) + (PLUS || (num < 0)))
		ft_write('0');
	ft_putnbrpos(num);
	while ((width < form.width - ft_intlen(num) + !SPACE))
	{
		ft_write(' ');
		width++;
	}
}

void		ft_intright(long long num, t_format form)
{
	int 	width;
	int 	max;
	int 	len;

	len = ft_intlen(num);
	if (!form.precision && num == 0)
		len = 0;
	max = ft_max(form.precision, len);
	width = 0;
	if (form.width < max)
		form.width = max;
	if (SPACE && !PLUS && num >=0)
	{
		ft_write(' ');
		form.width--;
	}
	while ((width < form.width - max - ft_max(PLUS, num < 0)) && !(ZERO && form.precision == -1))
	{
		ft_write(' ');
		width++;
	}
	if (PLUS || num < 0)
	{
		ft_write(num >= 0  ? '+' : '-');
		width++;
	}
	if (form.precision >= form.width && (PLUS || (num < 0)))
		width--;
	while ((width++ < form.width - len) && (form.precision > len || (ZERO && form.precision == -1)))
		ft_write('0');
	if (form.precision || num != 0)
		ft_putnbrpos(num);
}

void		ft_flagint(long long num, char *ss)
{
	t_format		form;

	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	if (!MINUS)
		ft_intright(num, form);
	else
		ft_intleft(num, form);
	free(form.flag);
}
