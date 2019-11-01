/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:17:17 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/01 22:16:54 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabaseunsigned(unsigned long long num, char *str, int base)
{
	int		i;
	int		rem;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9 ? (rem - 10) + 'a' : rem + '0');
		num = num / base;
	}
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

char				*ft_itoabase(long long num, char* str, int base)
{
	int i; 
	int	flag;
	
	i = 0;
	flag = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		flag = 1;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9 ? (rem-10) + 'a' : rem + '0');
		num = num/base;
	}
	if (flag)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}
