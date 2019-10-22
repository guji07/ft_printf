#include "libft/libft.h"

int main(void)
{
	printf("[%i]\n", -2222123);
	ft_printf("[%i]\n", -2222123);
	printf("[%1.11i]\n", -3333);
	ft_printf("[%1.11i]\n", -3333);
	printf("[%0.7i]\n", -3333);
	ft_printf("[%0.7i]\n", -3333);
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
	printf("[%0.3ss is a string]\n", "this");
	ft_printf("[%0.3ss is a string]\n", "this");
	printf("[%- 12.5i]\n", 456);
	ft_printf("[%- 12.5i]\n", 456);
	printf("[% 1.4i]\n", 456);
	ft_printf("[% 1.4i]\n", 456);
	printf("[%-8.5i]\n", -123);
	ft_printf("[%-8.5i]\n", -123);
	printf("[%-8.15i]\n", -123);
	ft_printf("[%-8.15i]\n", -123);
	printf("[%1.11i]\n", 0);
	ft_printf("[%1.11i]\n", 0);
	long int i = -500000;
	printf("[%li]\n", i);
	ft_printf("[%li]\n", i);
	return (0);
}
