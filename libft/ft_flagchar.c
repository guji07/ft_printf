#include "libft.h"

void		ft_flagchar(char *ss, char c)
{
	t_format	form;
	int 		i;

	i = 0;
	form.width = ft_parse_width(ss);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	if (form.flag[0] == 1)
		ft_write(&c, 1);
	while (i < form.width - 1)
	{
		i++;
		ft_write(" ", 1);
	}
	if (form.flag[0] == 0)
		ft_write(&c, 1);
	free(form.flag);
}
