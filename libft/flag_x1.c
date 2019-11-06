/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:00:51 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_xtetleft(char *str, t_format form, int mode)
{
	int		precision;
	int		len;
	int		width;

	len = ft_strlen(str);
	precision = ft_max(form.precision, len);
	width = form.width - precision;
	if (HASHTAG && str[0] != '0')
	{
		ft_putstr(mode == 2 ? "0X" : "0x");
		width -= 2;
	}
	while (precision - len)
	{
		precision--;
		ft_write("0", 1);
	}
	if (mode == 1)
		ft_putstr(str);
	else
		ft_putupstr(str);
	while (width-- > 0)
		ft_write(" ", 1);
}

void				ft_xtetright(char *str, t_format form, int mode)
{
	int		width;
	int		precision;
	int		len;

	len = ft_strlen(str);
	precision = ft_max(form.precision, len);
	width = form.width - precision;
	if (HASHTAG && str[0] != '0')
		width -= 2;
	if ((ZERO && form.precision == -1))
		if (HASHTAG && str[0] != '0')
			ft_putstr(mode == 2 ? "0X" : "0x");
	while (width-- > 0)
		ft_write((ZERO && form.precision == -1) ? "0" : " ", 1);
	if (!(ZERO && form.precision == -1))
		if (HASHTAG && str[0] != '0')
			ft_putstr(mode == 2 ? "0X" : "0x");
	while (precision-- - len)
		ft_write("0", 1);
	if (mode == 2)
		ft_putupstr(str);
	else
		ft_putstr(str);
}

int					ft_checkzero(char *ss)
{
	int		i;
	int		len;
	int		flag;

	i = 0;
	flag = 0;
	len = ft_len_to_type(ss);
	while (ss[i] && ss[i] != '.' && i < len)
		i++;
	if (ss[i] == '.')
		i++;
	else
		return (flag);
	if ((ss[i] == '0' || (ss[i] > '9' || ss[i] <= '0')))
		flag = 1;
	else
		flag = 0;
	return (flag);
}

void				ft_flagxtet(unsigned long long num, char *ss, int mode)
{
	t_format	form;
	char		*str;

	str = (char*)ft_memalloc(21);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	ft_itoabaseunsigned(num, str, 16);
	if (str[0] == '0' && ft_checkzero(ss))
	{
		if (!MINUS)
			ft_costylright(form);
		else
			ft_costylleft(form);
	}
	else if (MINUS)
		ft_xtetleft(str, form, mode);
	else
		ft_xtetright(str, form, mode);
	free(str);
	free(form.flag);
}

void				ft_xtet(char *ss, va_list ap, int mode)
{
	int		size;

	size = ft_parse_size(ss);
	if (size == H)
		ft_flagxtet((unsigned short int)va_arg(ap, unsigned int), ss, mode);
	else if (size == HH)
		ft_flagxtet((unsigned char)va_arg(ap, unsigned int), ss, mode);
	else if (size == L)
		ft_flagxtet((unsigned long int)va_arg(ap, unsigned long int), ss, mode);
	else if (size == LL || ft_parse_name(ss) == 60)
		ft_flagxtet(va_arg(ap, unsigned long long int), ss, mode);
	else if (size == 0)
		ft_flagxtet(va_arg(ap, unsigned int), ss, mode);
}
