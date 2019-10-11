#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//printf("printf:");
	//printf("...\n");
	//printf("%cijdfngijndfjng 34234432234\n", 50);
	ft_printf("integer 56: %i\n%c%c%c\n%s", 56, 'x', 'u', 'y', "str");
	return 0;
}