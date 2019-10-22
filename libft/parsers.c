#include "libft.h"

int 		ft_parse_size(char *ss)
{
	int 	i;
	int 	len;

	i = 0;
	len = ft_len_to_type(ss);
	while (ss[i] && i < len)
	{
		if (ss[i] == 'h')
		{
			if (ss[i + 1] == 'h')
				return (2);
			else
				return (1);
		}
		if (ss[i] == 'l')
		{
			if (ss[i + 1] == 'l')
				return (4);
			else
				return (3);
		}
		i++;
	}
	return (0);
}

int 		ft_parse_precision(char *ss)
{
	int 	i;
	int 	len;

	i = 0;
	len = ft_len_to_type(ss);
	while (ss[i] && ss[i] != '.' && i < len)
		i++;
	if (ss[i] == '.')
		return (ft_atoi(ss + i + 1));
	return (-1);
}

int 			ft_parse_width(char *ss)
{
	int 	i;

	i = 1;
	while ((ss[i] == '0' || ss[i] == '+' || ss[i] == ' ' || ss[i] == '-' || ss[i] == '#') && ss[i])
	{
		i++;
	}
	if (ss[i] && (ss[i] >= '0' && ss[i] <= '9'))
		return (ft_atoi(ss + i));
	return (0);
}

int				*ft_parse_flag(int num, char *ss)
{
	int			i;
	int			*flag;

	flag = ft_memalloc(5 * sizeof(int));
	i = 0;
	while (i < 5)
		flag[++i] = 0;
	i = 0;
	while (ss[++i] && i <= num)
	{
		if (ss[i] == '-')
			flag[0] = 1;
		if (ss[i] == '+')
			flag[1] = 1;
		if (ss[i] == '0' && ft_strchr("+- #%", ss[i - 1]))
			flag[2] = 1;
		if (ss[i] == '#')
			flag[3] = 1;
		if (ss[i] == ' ')
			flag[4] = 1;
	}
	return (flag);
}

int 		ft_len_to_type(char *s)
{
	int 	i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'c')
			return (i);
		if (s[i] == 's')
			return (i);
		if (s[i] == 'd' || s[i] == 'i')
			return (i);
		if (s[i] == 'p')
			return (i);
		if (s[i] == 'o')
			return (i);
		if (s[i] == 'u')
			return (i);
		if (s[i] == 'x')
			return (i);
		if (s[i] == 'X')
			return (i);
		if (s[i] == 'f')
			return (i);
		if (s[i] == '%')
			return (i);
	}
	return (0);
}

int 		ft_parse_name(char *s)
{
	int 	i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'c')
			return (10);
		if (s[i] == 's')
			return (20);
		if (s[i] == 'd' || s[i] == 'i')
			return (30);
		if (s[i] == 'p')
			return (40);
		if (s[i] == 'o')
			return (50);
		if (s[i] == 'u')
			return (60);
		if (s[i] == 'x')
			return (70);
		if (s[i] == 'X')
			return (80);
		if (s[i] == 'f')
			return (90);
		if (s[i] == '%')
			return (100);
	}
	return (0);
}