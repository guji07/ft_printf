#include "libft.h"

void				ft_xtetleft(char *str, t_format form, int mode)
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
	if (mode == 2)
		ft_putupstr(str);
	else
		ft_putstr(str);
	while ((width < form.width - (int)ft_strlen(str) + !SPACE))
	{
		ft_write(' ');
		width++;
	}
}

void				ft_xtetright(char *str, t_format form, int mode)
{
	int 	width;
	int 	max;
	int 	len;

	width = 0;
	if (HASHTAG)
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
	if (HASHTAG)
		ft_write('0');
	if (form.precision >= form.width && (PLUS))
		width--;
	while ((width++ < form.width - len) && (form.precision > len || (ZERO && form.precision == -1)))
		ft_write('0');
	if (form.precision || str[0] != '0')
	{
		if (mode == 2)
			ft_putupstr(str);
		else
			ft_putstr(str);
	}
}

void		ft_flagxtet(unsigned long long num, char *ss, int mode)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(40);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabase(num, str, 16);
	if (!MINUS)
		ft_xtetright(str, form, mode);
	else
		ft_xtetleft(str, form, mode);
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
		num = va_arg(ap, int);
		ft_flagxtet((unsigned short int)num, ss, mode);
	}
	if (size == hh)
	{
		num = va_arg(ap, int);
		ft_flagxtet((unsigned char)num, ss, mode);
	}
	if (size == l)
	{
		num = va_arg(ap, long int);
		ft_flagxtet((unsigned long int)num, ss, mode);
	}
	if (size == ll)
	{
		num = va_arg(ap, unsigned long long int);
		ft_flagxtet(num, ss, mode);
	}
	if (size == 0)
	{
		num = va_arg(ap, int);
		ft_flagxtet((int)num, ss, mode);
	}
}