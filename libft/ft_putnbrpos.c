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

static	long long	ft_whtnbr(long long num)
{
	int i;

	i = 0;
	if (num > 0)
		i = 0;
	if ((num < 0))
		i = 1;
	return (i);
}

static		void	ft_screen(long long nb)
{
	long long div;
	long long n;

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
	if ((ft_whtnbr(nb)) == 0)
		ft_screen(nb);
	else if ((ft_whtnbr(nb)) == 1)
	{
		nb = nb * (-1);
		ft_screen(nb);
	}
	else if ((ft_whtnbr(nb)) == 2)
	{
		nb = nb / 10;
		ft_screen(-nb);
		ft_putchar('8');
	}
}
