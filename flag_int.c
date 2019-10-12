#include "ft_printf.h"

void 	ft_flagint(int num, char *ss)
{
	t_format		form;

	form = ft_parse_flag(num, ss);

	ft_putnbr(num);
}