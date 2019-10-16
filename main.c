#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int number    =  5;
	char *pointer = "little";

	printf("[%.i]\n", 0);
	ft_printf("[%.i]\n", 0);
	printf("[%15.11i]\n", -2222);
	ft_printf("[%15.11i]\n", -2222);
	printf("[%0.11i]\n", -3333);
	ft_printf("[%0.11i]\n", -3333);
	printf("[%0.0i]\n", -3333);
	ft_printf("[%0.0i]\n", -3333);
	printf("[%i]\n", -4444);
	ft_printf("[%i]\n", -4444);
	printf("[%i]\n", 6666);
	ft_printf("[%i]\n", 6666);
	printf("[%+i]\n", 5555);
	ft_printf("[%+i]\n", 5555);
	printf("[%+0.1i]\n", -7777);
	ft_printf("[%+0.1i]\n", -7777);
	printf("[%+0.1i]\n", +7777);
	ft_printf("[%+0.1i]\n", +7777);
	printf("[%+0.1i]\n", -7777);
	ft_printf("[%+0.1i]\n", -7777);
	return (0);
}
