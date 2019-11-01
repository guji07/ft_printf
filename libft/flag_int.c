#include "libft.h"

void		ft_int(char *ss, va_list ap)
{
	int				size;

	size = ft_parse_size(ss);
	if (size == h)
		ft_flagint((short int)va_arg(ap, int), ss);
	else if (size == hh)
		ft_flagint((signed char)va_arg(ap, int), ss);
	else if (size == l)
		ft_flagint((long int)va_arg(ap, long int), ss);
	else if (size == ll)
		ft_flagint(va_arg(ap, long long int), ss);
	else
		ft_flagint(va_arg(ap, int), ss);
}

int			ft_sing(int k, long long num)
{
	if (k || num < 0)
	{
		ft_write(num >= 0 ? "+" : "-", 1);
		return (1);
	}
	return (0);
}

void		ft_intleft(long long num, t_format form)
{
	int		width;
	int		max;

	if (PLUS || num < 0)
		SPACE = 0;
	max = ft_max(form.precision, ft_intlen(num));
	form.width = ft_max(form.width, max);
	width = 0;
	if (SPACE && !PLUS && num >= 0)
		ft_write(" ", 1);
	width += ft_sing(PLUS, num);
	while (width++ < form.precision - ft_intlen(num) + (PLUS || (num < 0)))
		ft_write("0", 1);
	if (form.precision || num != 0)
		ft_putnbrpos(num);
	else
		width--;
	while ((width < form.width - ft_intlen(num) + !SPACE))
	{
		ft_write(" ", 1);
		width++;
	}
}

void		ft_intright(long long num, t_format form)
{
	int		width;
	int		max;
	int		len;

	len = ft_intlen(num);
	if (!form.precision && num == 0)
		len = 0;
	if (SPACE && !PLUS && num >= 0)
	{
		ft_write(" ", 1);
		form.width--;
	}
	max = ft_max(form.precision, len);
	width = 0;
	if (form.width < max)
		form.width = max;
	while ((width < form.width - max -
	ft_max(PLUS, num < 0)) && !(ZERO && form.precision == -1))
	{
		ft_write(" ", 1);
		width++;
	}
	width += ft_sing(PLUS, num);
	if (form.precision >= form.width && (PLUS || (num < 0)))
		width--;
	while ((width++ < form.width - len) && (form.precision > len
	|| (ZERO && form.precision == -1)))
		ft_write("0", 1);
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
