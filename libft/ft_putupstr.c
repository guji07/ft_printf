#include "libft.h"

void		ft_putupstr(char *s)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			ft_putchar(s[i] - 32);
		else
			ft_write(s + i, 1);
		i++;
	}
}