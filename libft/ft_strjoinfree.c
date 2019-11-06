/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:00:51 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strjoinfree(char const *s1, char const *s2)
{
	int		j;
	char	*str;
	int		i;

	i = -1;
	j = -1;
	str = NULL;
	if (s1 && s2)
	{
		if ((str = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			while (s1[++i])
				str[i] = s1[i];
			while (s2[++j])
				str[i++] = s2[j];
			str[i] = '\0';
		}
	}
	free((void*)s1);
	return (str);
}
