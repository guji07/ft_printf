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
	char		*buf;
	t_format	form;
	int 		size;

	size = 0;
	while (num > 1)
	{
		buf = (char*)malloc(21);
		while ((num) > 18446744073709551615.0)
		{
			size++;
			num /= 10;
		}
		ft_itoabaseunsigned((unsigned long long)num, buf, 10);
		num = num - ((size_t)num);
		num *= ft_pow(10, size > 20 ? 20 : size);
		printf("%s\n", buf);
		free(buf);
	}
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