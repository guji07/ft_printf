/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:19:27 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/06 09:19:29 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	writestrings(char *str, t_format form, int i)
{
	if (MINUS)
	{
		ft_putnstr(str, form.precision);
		while (i++ < form.width)
			ft_write(" ", 1);
	}
	else
	{
		while (i++ < form.width)
			ft_write(" ", 1);
		ft_putnstr(str, form.precision);
	}
	free(form.flag);
}

void	ft_flagstr(char *str, char *ss)
{
	t_format	form;
	int			i;
	int			n;

	if (str)
	{
		n = ft_strlen(str);
		i = 0;
		form.width = ft_parse_width(ss);
		form.precision = (int)(ft_parse_precision(ss));
		form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
		i += (((form.precision > n) ||
				(form.precision == -1)) ? n : form.precision);
		writestrings(str, form, i);
	}
	else
		ft_flagstr("(null)", ss);
}
