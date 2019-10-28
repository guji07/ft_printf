#include "libft.h"

void 	ft_write(char *s, int len)
{
	write(1, s, len);
	kolvo += len;
}
