/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:17:17 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/06 11:15:33 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_octetleft(char *str, t_format form)
{
	int		width;
	int		max;
	int		len;

	len = ft_strlen(str);
	width = 0;
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision < len)
		width++;
	max = ft_max(form.precision, len);
	if (form.width < max)
		form.width = max;
	while (width++ < form.precision - len + PLUS)
		ft_write("0", 1);
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision <= len)
		ft_write("0", 1);
	ft_putstr(str);
	width--;
	while ((width < form.width - len))
	{
		ft_write(" ", 1);
		width++;
	}
}

void				ft_octetright(char *str, t_format form)
{
	int		width;
	int		max;
	int		len;

	len = ((!form.precision && str[0] == '0') ? 0 : (int)ft_strlen(str));
	width = 0;
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision < len)
		width++;
	max = ft_max(form.precision, len);
	form.width = ft_max(form.width, max);
	while ((width < form.width - max - PLUS) && !(ZERO && form.precision == -1))
	{
		ft_write(" ", 1);
		width++;
	}
	if (form.precision >= form.width && (PLUS))
		width--;
	while ((width++ < form.width - len) &&
	(form.precision > len || (ZERO && form.precision == -1)))
		ft_write("0", 1);
	if (HASHTAG && ((!ft_strequ("0", str))) && form.precision <= len)
		ft_write("0", 1);
	if (form.precision || str[0] != '0')
		ft_putstr(str);
}

void				ft_writezeros(char *str, t_format form)
{
	int		i;

	i = -1;
	if (!MINUS)
	{
		while (++i < form.width - ft_max(form.precision, (str[0] == '0'
						&& !HASHTAG) ? 0 : ft_strlen(str)))
			ft_write(" ", 1);
		if (HASHTAG)
			ft_write("0", 1);
		else if (form.precision != 0)
			ft_write(" ", 1);
	}
	else
	{
		if (HASHTAG)
			ft_write("0", 1);
		else if (form.width)
			ft_write(" ", 1);
		while (++i < form.width - ft_max(form.precision, ft_strlen(str)))
			ft_write(" ", 1);
	}
}

void				ft_flagoctet(unsigned long long num, char *ss)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(40);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabaseunsigned(num, str, 8);
	if (str[0] == '0' && !form.precision)
		ft_writezeros(str, form);
	else if (!MINUS)
		ft_octetright(str, form);
	else
		ft_octetleft(str, form);
	free(str);
	free(form.flag);
}

void				ft_octet(char *ss, va_list ap)
{
	int			size;

	size = ft_parse_size(ss);
	if (size == H)
		ft_flagoctet((short unsigned)va_arg(ap, unsigned int), ss);
	else if (size == HH)
		ft_flagoctet((unsigned char)va_arg(ap, unsigned int), ss);
	else if (size == L)
		ft_flagoctet((unsigned long int)va_arg(ap, unsigned long int), ss);
	else if (size == LL)
		ft_flagoctet(va_arg(ap, unsigned long long int), ss);
	else if (size == 0)
		ft_flagoctet((unsigned int)va_arg(ap, unsigned int), ss);
}
