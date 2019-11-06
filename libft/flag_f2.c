/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:40:13 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/05 21:40:00 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_parse_precision(char *ss)
{
	int		i;
	int		len;

	i = 0;
	len = ft_len_to_type(ss);
	while (ss[i] && ss[i] != '.' && i < len)
		i++;
	if (ss[i] == '.')
		return (ft_atoi(ss + i + 1));
	return (-1);
}

void		ft_k2(t_format form, char *num, char *ss)
{
	if ((PLUS || num[0] == '-') && !ZERO)
	{
		ft_putchar(num[0] == '-' ? '-' : '+');
		if (num[0] == '-')
			num += 1;
	}
	ft_putstr(num);
	if (HASHTAG && ft_parse_precision(ss) == 0)
		ft_putchar('.');
}

char		*ft_k3(long double *num, t_format form)
{
	char	*buf;

	buf = (char*)ft_memalloc(23);
	if (*num < 0)
	{
		*num *= -1;
		buf[0] = '-';
		*num += (double)ft_okrug(form.precision);
		ft_itoabaseunsigned((unsigned long long)*num, buf + 1, 10);
	}
	else
	{
		*num += (double)ft_okrug(form.precision);
		ft_itoabaseunsigned((unsigned long long)*num, buf, 10);
	}
	*num = *num - ((size_t)*num);
	if (form.precision)
		buf[ft_strlen(buf)] = '.';
	return (buf);
}

double		ft_okrug(int i)
{
	double		k;

	k = 0.5;
	while (i-- > 0)
		k *= 0.1;
	return (k);
}
