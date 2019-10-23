#include "libft.h"

int			ft_unsignedintlen(unsigned long long int num)
{
	int						i;
	signed long long int	base;

	i = 19;
	base = 1000000000000000000;
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

void		ft_unsignedintleft(unsigned long long num, t_format form)
{
	int 	width;
	int 	max;

	max = ft_max(form.precision, ft_unsignedintlen(num));
	width = 0;
	if (form.width < max)
		form.width = max;
	while (width++ < form.precision - ft_unsignedintlen(num) + PLUS)
		ft_write('0');
	ft_putunsignednbrpos(num);
	while ((width < form.width - ft_unsignedintlen(num) + !SPACE))
	{
		ft_write(' ');
		width++;
	}
}

void		ft_unsignedintright(unsigned long long num, t_format form)
{
	int 	width;
	int 	max;
	int 	len;

	len = ft_unsignedintlen(num);
	if (!form.precision && num == 0)
		len = 0;
	max = ft_max(form.precision, len);
	width = 0;
	if (form.width < max)
		form.width = max;
	while ((width < form.width - max - PLUS) && !(ZERO && form.precision == -1))
	{
		ft_write(' ');
		width++;
	}
	if (form.precision >= form.width && (PLUS))
		width--;
	while ((width++ < form.width - len) && (form.precision > len || (ZERO && form.precision == -1)))
		ft_write('0');
	if (form.precision || num != 0)
		ft_putunsignednbrpos(num);
}

void		ft_flagunsignedint(unsigned long long num, char *ss)
{
	t_format		form;

	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	if (!MINUS)
		ft_unsignedintright(num, form);
	else
		ft_unsignedintleft(num, form);
}
