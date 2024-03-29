/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:16:02 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/04 14:20:22 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (s1 && s2)
	{
		i = -1;
		while (s1[++i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
		}
		if (s1[i] == s2[i])
			return (1);
		return (0);
	}
	return (0);
}
