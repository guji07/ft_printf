/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagf1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:40:13 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/05 21:40:00 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putfloatleft(char *ss, char *num, t_format form)
{
	int 			width;

	form.width = ft_parse_width(ss);
	width = (int)(form.width > (int)ft_strlen(num) ? form.width - ft_strlen(num) : 0);
	if (SPACE && !PLUS && num[0] != '-')
	{
		ft_putchar(' ');
		if (width > form.precision)
			width--;
	}
	if (PLUS && num[0] != '-')
	{
		ft_putchar('+');
		width--;
	}
	ft_putstr(num);
	if (HASHTAG && ft_parse_precision(ss) == 0)
	{
		ft_putchar('.');
		width--;
	}
	while (width-- > 0)
		ft_putchar(' ');
}

void		ft_putfloatright(char *ss, char *num, t_format form)
{
	int 			width;

	form.width = ft_parse_width(ss);
	if (SPACE && !PLUS && num[0] != '-')
	{
		ft_putchar(' ');
		if (form.width > form.precision)
			form.width--;
	}
	if ((PLUS || num[0] == '-') && ZERO)
	{
		ft_putchar(num[0] == '-' ? '-' : '+');
		if (num[0] == '-')
			num += 1;
		width = (int)(form.width > (int)ft_strlen(num) + 1 ? form.width - ft_strlen(num) - 1 : 0);
	}
	else
		width = (int)(form.width > (int)ft_strlen(num) ? form.width - ft_strlen(num) : 0);
	width -= (HASHTAG ? 1 : 0);
	while (width-- > 0 + (PLUS && !ZERO && num[0] != '-'))
		ft_putchar(ZERO ? '0' : ' ');
	ft_k2(form, num, ss);
}

void		ft_double(char *ss, long double num)
{
	char		*buf;
	t_format	form;
	char		c[2];

	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.precision = ft_parse_precision(ss) >= 0 ? ft_parse_precision(ss) : 6;
	buf = ft_k3(&num, form);
	while (form.precision-- > 0)
	{
		num *= 10;
		*c = (char)(((size_t)num % 10) + '0');
		num = num - (double)((size_t)num * 10 / 10);
		*(c + 1) = '\0';
		buf = ft_strjoinfree(buf, c);
	}
	form.precision = ft_parse_precision(ss) >= 0 ? ft_parse_precision(ss) : 6;
	if (!MINUS)
		ft_putfloatright(ss, buf, form);
	else
		ft_putfloatleft(ss, buf, form);
	free(buf);
	free(form.flag);
}

void		ft_float(char *ss, va_list ap)
{
	int 	size;

	size = ft_parse_size(ss);
	if (size == 5)
		ft_double(ss, va_arg(ap, long double));
	else
		ft_double(ss, va_arg(ap, double));
}
