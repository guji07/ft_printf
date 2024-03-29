/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:19:33 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/01 22:19:48 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnstr(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
	{
		write(1, str + i, 1);
		i++;
	}
	g_kolvo = g_kolvo + (int)i;
}
