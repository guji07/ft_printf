#include "libft.h"

void 	reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end)
	{
		ft_memswap(str+start, str+end);
		start++;
		end--;
	}
}