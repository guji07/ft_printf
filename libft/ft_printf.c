/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:00:51 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_format(char *ss, va_list ap)
{
	int		type;

	if ((type = ft_parse_name(ss)))
	{
		if (type == 10)
			ft_flagchar(ss, va_arg(ap, int));
		else if (type == 20)
			ft_flagstr(va_arg(ap, char*), ss);
		else if (type == 30)
			ft_int(ss, ap);
		else if (type == 40)
			ft_unsignedint(ss, ap);
		else if (type == 50)
			ft_octet(ss, ap);
		else if (type == 60)
			ft_ptet(ss, ap);
		else if (type == 70 || type == 80)
			ft_xtet(ss, ap, type == 70 ? 1 : 2);
		else if (type == 90)
			ft_float(ss, ap);
		else if (type == 100)
			ft_flagpercent(ss);
	}
	return (ft_len_to_type(ss));
}

int				ft_printf(char *str, ...)
{
	int			i;
	va_list		ap;

	if (!str)
		return (0);
	g_kolvo = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_write((str + i), 1);
		else
			i = i + ft_format(str + i, ap);
		i++;
	}
	return (g_kolvo);
}
