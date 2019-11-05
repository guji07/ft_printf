/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagpercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:20:59 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/01 21:21:37 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flagpercent(char *ss)
{
	t_format	form;
	int			i;

	form.width = ft_parse_width(ss);
	form.flag = ft_parse_flag(ft_len_to_type(ss), ss);
	i = 1;
	if (MINUS)
	{
		ft_write("%", 1);
		while (i++ < form.width)
			ft_write(" ", 1);
		return ;
	}
	while (i++ < form.width)
		ft_write(ZERO ? "0" : " ", 1);
	if (MINUS == 0)
		ft_write("%", 1);
	free(form.flag);
}
