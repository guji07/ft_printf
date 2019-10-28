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
		form.precision = (int)(ft_parse_precision(ss));
		form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
		if (MINUS)
		{
			ft_putnstr(str, form.precision);
			i += (((form.precision > n) || (form.precision == -1)) ? n : form.precision);
			while (i++ < form.width)
				ft_write(" ", 1);
		}
		else
		{
			i += (((form.precision > n) || (form.precision == -1)) ? n : form.precision);
			while (i++ < form.width)
				ft_write(" ", 1);
			ft_putnstr(str, form.precision);
		}
		free(form.flag);
	}
	else
		ft_flagstr("(null)", ss);
}