#include "libft.h"

void		ft_longdouble(char *ss, long double num)
{
	return ;
}

int 		ft_doublelen(double num)
{
	int 	i;

	i = 1;
	if (num < 1)
		return (i);
	while ((num /= 10) >= 1)
		i++;
	return (i);
}

void		ft_double(char *ss, double num)
{
	char		*s;
	t_format	form;
	int 		size;

	size = 0;
	form.precision = ft_parse_precision(ss);
	s = (char*)malloc(ft_doublelen(num) + form.precision + 2);
	printf("%s", s);
	while ((num) > 18446744073709551615.0)
	{
		size++;
		num /= 10;
	}
	ft_itoabaseunsigned((unsigned long long)num, s, 10);
}

void		ft_float(char *ss, va_list ap)
{
	int 	size;

	size = ft_parse_size(ss);
	if (size == 5)
		ft_longdouble(ss, va_arg(ap, long double));
	else
		ft_double(ss, va_arg(ap, double));
}