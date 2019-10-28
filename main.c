#include "libft/libft.h"
#include <limits.h>
//all p,i,s,d,u,c
int main(void)
{
	printf("[%x]\n", -42);
	ft_printf("[%x]\n", -42);
	printf("[%x]\n", 42);
	ft_printf("[%x]\n", 42);
	printf("[%3.x]\n", 0);
	ft_printf("[%3.x]\n", 0);
	printf("[%x]\n", -42);
	ft_printf("[%x]\n", -42);
	printf("[%#x]\n", 17);
	ft_printf("[%#x]\n", 17);
	printf("[%-#10.1x]\n", 1);
	ft_printf("[%-#10.1x]\n", 1);
	printf("[%-3.0x]\n", 0);
	ft_printf("[%-3.0x]\n", 0);
}
