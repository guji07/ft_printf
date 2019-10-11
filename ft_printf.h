#ifndef FTPRINTF_H
# define FTPRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef  struct				s_format
{
	int		flag;
}							t_format;

int			ft_printf(char* format, ...);
int			ft_format(char *ss, va_list ap, t_format form);
int 		ft_pos_conver(char *s);
int			ft_parse_flag(char *ss, int num);
int			ft_first_conver(char *s);
int			ft_get_all(char *ss, va_list ap);
#endif
