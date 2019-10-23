/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:39:02 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/04 14:25:52 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		int		ft_whtnbr(long long num)
{
	int		i;
	unsigned long long k;

	k = -9223372036854775808U;
	i = 0;
	if ((unsigned long long)num == k)
		i = 2;
	else if (num > 0)
		i = 0;
	else if ((num < 0))
		i = 1;
	return (i);
}

static		void	ft_screen(long long nb)
{
	long	long	div;
	long	long	n;

	n = 1;
	div = 1;
	while (div <= nb / 10)
	{
		n++;
		div = div * 10;
	}
	while (n > 0)
	{
		ft_putchar('0' + (int)(nb / div));
		nb = nb % div;
		div = div / 10;
		n--;
	}
}

void			ft_putnbrpos(long long nb)
{
	int 	flag;

	flag = ft_whtnbr(nb);
	if (flag == 0)
		ft_screen(nb);
	else if (flag == 1)
	{
		nb = nb * (-1);
		ft_screen(nb);
	}
	else if (flag == 2)
	{
		nb = nb / 10;
		ft_screen(-nb);
		ft_putchar('8');
	}
}
