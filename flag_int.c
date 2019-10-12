#include "ft_printf.h"

int		ft_int_withoutminus(int num, t_format form)
{
	int 	i;

	i = 0;
	if (form.flag[1] && num >= 0)
	{
		while (i++ < form.width - form.precision - ft_intlen(num))
			write(1, " ", 1);
		write(1, "+", 1);
		i = 0;
		while (i < form.precision - ft_intlen(num))
		{
			write(1, "0", 1);
			i++;
		}
		ft_putnbr(num);
	}
	if (form.flag[1] && num < 0)
	{
		while (i++ < form.width - form.precision - ft_intlen(num))
			write(1, " ", 1);
		i = 0;
		while (i < form.precision - ft_intlen(num))
		{
			write(1, "0", 1);
			i++;
		}
		ft_putnbr(num);
	}
	return (0);
}

int			ft_intlen(signed long long int num)
{
	int						i;
	signed long long int	base;

	i = 19;
	base = 1000000000000000000;
	if (num < 0)
	{
		num = -num;
		i = 20;
	}
	while (42)
	{
		if (num / base)
			return (i);
		base /= 10;
		i--;
	}
}

void		ft_flagint(int num, char *ss)
{
	t_format		form;

	form.width = ft_intlen(num);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	if (ft_parse_width(ss) > form.width)
		form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss) > ft_intlen(num) ? ft_parse_precision(ss) : ft_intlen(num);
	if (!form.flag[0])
		ft_int_withoutminus(num, form);
	else
		return ;
}