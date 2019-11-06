/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:21:57 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/01 21:34:05 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_ptetleft(char *str, t_format form, char *ss)
{
	int		width;
	int		max;

	width = 2;
	max = ft_max(form.precision, ft_strlen(str));
	if (form.width < max)
		form.width = max;
	while (width++ < form.precision - (int)ft_strlen(str) + PLUS)
		ft_write("0", 1);
	ft_putstr("0x");
	if (str[0] != '0' || ft_parse_precision(ss) == -1)
		ft_putstr(str);
	while ((width < form.width - (int)ft_strlen(str) + !SPACE))
	{
		ft_write(" ", 1);
		width++;
	}
}

void				ft_k5(int width, t_format form, int len, char *str)
{
	while ((width++ < form.width - len) &&
	(form.precision > len || (ZERO && form.precision == -1)))
		ft_write("0", 1);
	ft_putstr("0x");
	if (str[0] != '0' || form.precision == 1)
		ft_putstr(str);
}

void				ft_ptetright(char *str, t_format form)
{
	int		width;
	int		max;
	int		len;

	width = 1;
	len = ft_strlen(str);
	if (!form.precision && str[0] == '0')
		len = 0;
	max = ft_max(form.precision, len);
	if (form.width < max)
		form.width = max;
	while ((++width < form.width - max - PLUS)
	&& !(ZERO && form.precision == -1))
		ft_write(" ", 1);
	if (form.precision == 0 && str[0] == '0'
			&& str[1] == '\0' && !ft_strequ("0", str))
	{
		ft_write(" ", 1);
		return ;
	}
	if (form.precision >= form.width && (PLUS))
		width--;
	ft_k5(width, form, len, str);
}

void				ft_flagptet(unsigned long long num, char *ss)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(21);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabaseunsigned(num, str, 16);
	if (!ft_checkzero(ss))
		form.precision = 1;
	if (!MINUS)
		ft_ptetright(str, form);
	else
		ft_ptetleft(str, form, ss);
	free(str);
	free(form.flag);
}

void				ft_ptet(char *ss, va_list ap)
{
	int						size;

	size = ft_parse_size(ss);
	if (size == H)
		ft_flagptet((unsigned short int)va_arg(ap, unsigned int), ss);
	else if (size == HH)
		ft_flagptet((unsigned char)va_arg(ap, unsigned int), ss);
	else if (size == L)
		ft_flagptet((unsigned long int)va_arg(ap, unsigned long int), ss);
	else if (size == LL || ft_parse_name(ss) == 60)
		ft_flagptet(va_arg(ap, unsigned long long int), ss);
	else if (size == 0)
		ft_flagptet(va_arg(ap, unsigned int), ss);
}
