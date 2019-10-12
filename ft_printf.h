#ifndef FTPRINTF_H
# define FTPRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

typedef  struct				s_format
{
	int		flag[5];
}							t_format;

int			ft_printf(char* format, ...);
int 		ft_conver_name(char *s);
int 		ft_conver_pos(char *s);
t_format	ft_parse_flag(int num, char *ss);
void		ft_flagint(int num, char *ss);

#endif
