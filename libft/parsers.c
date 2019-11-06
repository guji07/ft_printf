/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:26:48 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/06 09:28:05 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_parse_size(char *ss)
{
	int		i;
	int		n;

	n = ft_len_to_type(ss);
	i = -1;
	while (ss[++i] && i < n)
	{
		if (ss[i] == 'h')
		{
			if (ss[i + 1] == 'h')
				return (2);
			return (1);
		}
		if (ss[i] == 'l')
		{
			if (ss[i + 1] == 'l')
				return (4);
			return (3);
		}
		if (ss[i] == 'L' && ss[i + 1] == 'f')
			return (5);
	}
	return (0);
}

int			ft_parse_width(char *ss)
{
	int		i;

	i = 1;
	while ((ss[i] == '0' || ss[i] == '+' ||
	ss[i] == ' ' || ss[i] == '-' || ss[i] == '#') && ss[i])
		i++;
	if (ss[i] && (ss[i] >= '0' && ss[i] <= '9'))
		return (ft_atoi(ss + i));
	return (0);
}

int			*ft_parse_flag(int num, char *ss)
{
	int			i;
	int			*flag;

	flag = ft_memalloc(5 * sizeof(int));
	i = 0;
	while (i < 5)
		flag[++i] = 0;
	i = 0;
	while (ss[++i] && i <= num)
	{
		if (ss[i] == '-')
			flag[0] = 1;
		if (ss[i] == '+')
			flag[1] = 1;
		if (ss[i] == '0' && ft_strchr("+- #%", ss[i - 1]))
			flag[2] = 1;
		if (ss[i] == '#')
			flag[3] = 1;
		if (ss[i] == ' ')
			flag[4] = 1;
	}
	return (flag);
}

int			ft_len_to_type(char *s)
{
	int		i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'p')
			return (i);
		if (s[i] == 'd' || s[i] == 'i')
			return (i);
		if (s[i] == 'u' || s[i] == 'o')
			return (i);
		if (s[i] == 'X' || s[i] == 'x')
			return (i);
		if (s[i] == '%' || s[i] == 'f')
			return (i);
	}
	return (0);
}

int			ft_parse_name(char *s)
{
	int		i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'c' || s[i] == 's')
			return (s[i] == 'c' ? 10 : 20);
		if (s[i] == 'd' || s[i] == 'i')
			return (30);
		if (s[i] == 'u' || s[i] == 'o')
			return (s[i] == 'u' ? 40 : 50);
		if (s[i] == 'p')
			return (60);
		if (s[i] == 'x')
			return (70);
		if (s[i] == 'X')
			return (80);
		if (s[i] == 'f')
			return (90);
		if (s[i] == '%')
			return (100);
	}
	return (0);
}
