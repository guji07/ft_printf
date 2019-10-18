#include "libft.h"

void  	ft_flagpercent(char *ss)
{
	t_format	form;
	int 		i;

	form.width = ft_parse_width(ss);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	if (form.flag[0] == 1)
		ft_write('%');
	i = 1;
	while (i++ < form.width)
		ft_write(' ');
	if (form.flag[0] == 0)
		ft_write('%');
}