#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int number    =  5;
	char *pointer = "little";
	printf("%s%i%d\n", "[123]  ", 2, 900);
	ft_printf("%s%i%d", "[123]  \n", 2, 900);
	return (0);
}
