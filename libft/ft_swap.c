/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:51:40 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/05 13:46:09 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	ft_memswap(char *s1,char *s2)
{
	char s[1];

	s[0] = *s1;
	*s1 = *s2;
	*s2 = s[0];
}