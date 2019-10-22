#include "libft.h"

int			ft_intlen(signed long long int num)
{
	int						i;
	signed long long int	base;

	i = 19;
	base = 1000000000000000000;
	if (num < 0)
		num = -num;
	if (num == 0)
		return (1);
	while (42)
	{
		if (num / base)
			return (i);
		base /= 10;
		i--;
	}
}
int 		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
void		ft_intright(int num, char *ss, t_format form)
{
	int 	width;
	int 	max;

	max = ft_max(form.precision, ft_intlen(num));
	width = 0;
	if (form.width < max)
	{
		form.width = max;
	}
	while (width < form.width - max - ft_max(PLUS, num <= 0))
	{
		ft_write(' ');
		width++;
	}
	if (PLUS || num <= 0)
	{
		ft_write(num >= 0  ? '+' : '-');
		width++;
	}
	while ((width++ < form.width - ft_intlen(num)) && (form.precision > ft_intlen(num)))
		ft_write('0');
	ft_putnbrpos(num);
}

void		ft_flagint(int num, char *ss)
{
	t_format		form;

	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	if (!MINUS)
		ft_intright(num, ss, form);
}
