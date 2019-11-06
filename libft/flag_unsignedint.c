/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_unsignedint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:00:51 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_unsignedint(char *ss, va_list ap)
{
	int		size;

	size = ft_parse_size(ss);
	if (size == H)
		ft_flagunsignedint((short unsigned int)va_arg(ap, unsigned int), ss);
	if (size == HH)
		ft_flagunsignedint((unsigned char)va_arg(ap, unsigned int), ss);
	if (size == L)
		ft_flagunsignedint((unsigned long int)
		va_arg(ap, unsigned long int), ss);
	if (size == LL)
		ft_flagunsignedint((unsigned long long)
		va_arg(ap, unsigned long long int), ss);
	if (size == 0)
		ft_flagunsignedint((unsigned int)va_arg(ap, unsigned int), ss);
}

void		ft_unsignedintleft(unsigned long long num, t_format form)
{
	int		width;
	int		max;

	max = ft_max(form.precision, ft_unsignedintlen(num));
	width = 0;
	if (form.width < max)
		form.width = max;
	while (width++ < form.precision - ft_unsignedintlen(num) + PLUS)
		ft_write("0", 1);
	if (form.precision || num != 0)
		ft_putunsignednbrpos(num);
	else
		width--;
	while ((width < form.width - ft_unsignedintlen(num) + !SPACE))
	{
		ft_write(" ", 1);
		width++;
	}
}

void		ft_unsignedintright(unsigned long long num, t_format form)
{
	int		width;
	int		max;
	int		len;

	len = ft_unsignedintlen(num);
	if (!form.precision && num == 0)
		len = 0;
	max = ft_max(form.precision, len);
	width = -1;
	if (form.width < max)
		form.width = max;
	while ((++width < form.width -
	max - PLUS) && !(ZERO && form.precision == -1))
		ft_write(" ", 1);
	if (form.precision >= form.width && (PLUS))
		width--;
	while ((width++ < form.width - len) &&
	(form.precision > len || (ZERO && form.precision == -1)))
		ft_write("0", 1);
	if (form.precision || num != 0)
		ft_putunsignednbrpos(num);
}

void		ft_flagunsignedint(unsigned long long num, char *ss)
{
	t_format	form;

	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	form.width = ft_parse_width(ss);
	form.precision = ft_parse_precision(ss);
	if (!MINUS)
		ft_unsignedintright(num, form);
	else
		ft_unsignedintleft(num, form);
	free(form.flag);
}
