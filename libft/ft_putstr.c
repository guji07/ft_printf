/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:00:33 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/04 14:09:56 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char const *s)
{
	int i;

	if (s)
	{
		i = ft_strlen(s);
		ft_write((char*)s, i);
	}
	else
		ft_putstr("(null)");
}
