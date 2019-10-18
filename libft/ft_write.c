#include "libft.h"

void 	ft_write(int c)
{
	write(1, &c, 1);
	kolvo++;
}
