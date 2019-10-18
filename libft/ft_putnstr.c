#include "libft.h"

void 	ft_putnstr(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
	{
		write(1, str + i, 1);
		i++;
	}
	kolvo = kolvo + (int)i;
}