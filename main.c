#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int 	i;

	printf("%p", &i);
	printf("\n");
	ft_printf("%p", &i);
	return 0;
}