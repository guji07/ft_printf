#include "libft.h"

long double		ft_pow(long double num, int power)
{
	int		i;
	int 	k;
	i = 0;
	k = num;
	while (++i < power)
		num *= k;
	return(num);
}