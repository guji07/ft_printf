#include "libft.h"

void		ft_putfloatleft(char *ss, char *num, t_format form)
{
	int 			width;

	form.width = ft_parse_width(ss);
	width = (int)(form.width > (int)ft_strlen(num) ? form.width - ft_strlen(num) : 0);
	if (SPACE && !PLUS && num[0] != '-')
	{
		ft_putchar(' ');
		if (width > form.precision)
			width--;
	}
	if (PLUS && num[0] != '-')
	{
		ft_putchar('+');
		width--;
	}
	ft_putstr(num);
	if (HASHTAG && ft_parse_precision(ss) == 0)
	{
		ft_putchar('.');
		width--;
	}
	while (width-- > 0)
		ft_putchar(' ');
}

void		ft_putfloatright(char *ss, char *num, t_format form)
{
	int 			width;

	form.width = ft_parse_width(ss);
	if (SPACE && !PLUS && num[0] != '-')
	{
		ft_putchar(' ');
		if (form.width > form.precision)
			form.width--;
	}
	if ((PLUS || num[0] == '-') && ZERO)
	{
		ft_putchar(num[0] == '-' ? '-' : '+');
		if (num[0] == '-')
			num += 1;
		width = (int)(form.width > (int)ft_strlen(num) + 1 ? form.width - ft_strlen(num) - 1 : 0);
	}
	else
		width = (int)(form.width > (int)ft_strlen(num) ? form.width - ft_strlen(num) : 0);
	width -= (HASHTAG ? 1 : 0);
	while (width-- > 0 + (PLUS && !ZERO && num[0] != '-'))
		ft_putchar(ZERO ? '0' : ' ');
	if ((PLUS || num[0] == '-') && !ZERO)
	{
		ft_putchar(num[0] == '-' ? '-' : '+');
		if (num[0] == '-')
			num += 1;
	}
	ft_putstr(num);
	if (HASHTAG && ft_parse_precision(ss) == 0)
		ft_putchar('.');
}

void				ft_okrug2(char *buf, t_format form, double num)
{
	int 	i;
	int 	len;
	int 	c;
	int 	j;

	j = 0;
	num *= 10;
	c = (char)(((size_t)num % 10) + '0');
	i = 0;
	len = ft_strlen(buf);
	while (i < len && buf[i] != '.')
		i++;
	if (buf[i] == '.')
		i++;
	else
		return ;
	while (j < form.precision - 1)
		j++;
	i += j;
	if (buf[i] > '5' && buf[i] < '9')
	{
		if (c > '0' && c <= '9')
			buf[i]++;
	}
	else if (buf[i] == '9' && c > '0' && c <= '9')
	{
		buf[i] = '0';
		if (buf[i - 1] != '.')
			buf[i - 1]++;
	}
}

double 		ft_okrug(int i)
{
	double		k;

	k = 0.5;
	while (i-- > 0)
		k *= 0.1;
	return (k);
}

void		ft_double(char *ss, long double num)
{
	char		*buf;
	t_format	form;
	char		c[2];

	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.precision = ft_parse_precision(ss) >= 0 ? ft_parse_precision(ss) : 6;
	buf = (char*)malloc(23);
	if (num < 0)
	{
		num *= -1;
		buf[0] = '-';
		num += (double)ft_okrug(form.precision);
		ft_itoabaseunsigned((unsigned long long) num, buf + 1, 10);
	}
	else
	{
		num += ft_okrug(form.precision);
		ft_itoabaseunsigned((unsigned long long) num, buf, 10);
	}
	num = num - ((size_t) num);
	if (form.precision)
		buf[ft_strlen(buf)] = '.';
	while (form.precision-- > 0)
	{
		num *= 10;
		*c = (char)(((size_t)num % 10) + '0');
		num = num - (double)((size_t)num * 10 / 10);
		*(c + 1) = '\0';
		free(buf);
		buf = ft_strjoin(buf, c);
	}
	form.precision = ft_parse_precision(ss) >= 0 ? ft_parse_precision(ss) : 6;
	//ft_okrug2(buf, form, num);
	if (!MINUS)
		ft_putfloatright(ss, buf, form);
	else
		ft_putfloatleft(ss, buf, form);
	free(buf);
	free(form.flag);
}

void		ft_float(char *ss, va_list ap)
{
	int 	size;

	size = ft_parse_size(ss);
	if (size == 5)
		ft_double(ss, va_arg(ap, long double));
	else
		ft_double(ss, va_arg(ap, double));
}