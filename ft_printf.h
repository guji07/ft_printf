#ifndef FTPRINTF_H
# define FTPRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

typedef  struct				s_format
{
	int			*flag;
	int 		width;
	int 		precision;
}							t_format;

int			ft_printf(char* format, ...);
int 		ft_parse_name(char *s);
int 		ft_len_to_type(char *s);

int			*ft_parse_flag(int num, char *ss);
int 		ft_parse_width(char *ss);
int 		ft_parse_precision(char *ss);

int			ft_intlen(signed long long int num);
void		ft_flagint(int num, char *ss);

#endif
