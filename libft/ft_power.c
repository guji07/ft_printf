#include "libft.h"

long double		ft_pow(long double num, int power)
{
	int		i;
	int 	k;
	i = 0;
	k = num;
	if (power == 0)
		return (1);
	while (++i < power)
		num *= k;
	return(num);
}