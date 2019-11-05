/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:00:51 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_costylleft(t_format form)
{
	int		width;
	int		precision;

	precision = form.precision;
	width = form.width - precision;
	while (precision > 0)
	{
		precision--;
		ft_write("0", 1);
	}
	while (width > 0)
	{
		ft_write(" ", 1);
		width--;
	}
}

void				ft_costylright(t_format form)
{
	int		width;
	int		precision;

	precision = form.precision;
	width = form.width - precision;
	while (width > 0)
	{
		ft_write(" ", 1);
		width--;
	}
	while (precision > 0)
	{
		precision--;
		ft_write("0", 1);
	}
}
