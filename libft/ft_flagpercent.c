#include "libft.h"

void  	ft_flagpercent(char *ss)
{
	t_format	form;
	int 		i;

	form.width = ft_parse_width(ss);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	i = 1;
	if (MINUS)
	{
		ft_write('%');
		while (i++ < form.width)
			ft_write(' ');
		return;
	}
	while (i++ < form.width)
		ft_write(ZERO ? '0' : ' ');
	if (MINUS == 0)
		ft_write('%');
	free(form.flag);
}