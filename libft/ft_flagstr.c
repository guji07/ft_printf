#include "libft.h"

void 	ft_flagstr(char *str, char *ss)
{
	t_format	form;
	int			i;
	int 		n;

	if (str)
	{
		n = ft_strlen(str);
		i = 0;
		form.width = ft_parse_width(ss);
		form.precision = (int) (ft_parse_precision(ss) == -1 ? n : ft_parse_precision(ss));
		form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
		if (form.flag[0] == 1)
		{
			ft_putnstr(str, form.precision);
			if (form.width > n)
				while (i++ < form.width - (n < form.precision ? n : form.precision))
					ft_write(' ');
		}
		else
		{
			if (form.width > n || form.precision < form.width)
				while (i++ < form.width - (n < form.precision ? n : form.precision))
					ft_write(' ');
			ft_putnstr(str, form.precision);
		}
		free(form.flag);
	}
	else
		ft_putstr("(null)");
}