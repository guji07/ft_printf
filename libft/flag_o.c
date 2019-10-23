#include "libft.h"

static		void 	reverse(char str[], int length)
{
	int start = 0;
	int end = length -1;
	while (start < end)
	{
		ft_memswap(str+start, str+end);
		start++;
		end--;
	}
}

char				*ft_itoabase(long long num, char* str, int base)
{
	int i = 0;
	int	flag = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		flag = 1;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9 ? (rem-10) + 'a' : rem + '0');
		num = num/base;
	}
	if (flag)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

void				ft_leftoctet(char *str, t_format form)
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

void				ft_rigthoctet(char *str, t_format form)
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
		ft_putstr(str);
}

void				ft_printoctet(long long num, char *ss, int base)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(40);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabase(num, str, base);
	if (!MINUS)
		ft_rigthoctet(str, form);
	else
		ft_leftoctet(str, form);
	free(str);
	free(form.flag);
}

void				ft_flago(char *ss, va_list ap, int base)
{
	int				size;
	long long int 	num;

	size = ft_parse_size(ss);
	if (size == h)
	{
		num = va_arg(ap, int);
		ft_printoctet((short int)num, ss, base);
	}
	if (size == hh)
	{
		num = va_arg(ap, int);
		ft_printoctet((signed char)num, ss, base);
	}
	if (size == l)
	{
		num = va_arg(ap, long int);
		ft_printoctet((long int)num, ss, base);
	}
	if (size == ll)
	{
		num = va_arg(ap, long long int);
		ft_printoctet(num, ss, base);
	}
	if (size == 0)
	{
		num = va_arg(ap, int);
		ft_printoctet((int)num, ss, base);
	}
}