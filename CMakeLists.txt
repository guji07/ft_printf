cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf main.c ft_printf.c ft_printf.h libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putstr.c)