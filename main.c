#include "libft/libft.h"

int main(void)
{
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
	printf("[%10s is a string]\n", "this");
	ft_printf("[%10s is a string]\n", "this");
	printf("[%012.5i]\n", 456);
	ft_printf("[%012.5i]\n", 456);
	return (0);
}
