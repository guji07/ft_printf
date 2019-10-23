cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
set(LIBPATH ${CMAKE_SOURCE_DIR}/libft)

#add_executable(main main.c libft/libft.h)
#target_link_libraries(main ${CMAKE_SOURCE_DIR}/libft/libft.a)
add_executable(printf
        ${LIBPATH}/ft_printf ${LIBPATH}/ft_putnbrpos
        ${LIBPATH}/ft_write ${LIBPATH}/flag_int ${LIBPATH}/ft_putchar ${LIBPATH}/ft_putstr
        ${LIBPATH}/ft_printf ${LIBPATH}/parsers ${LIBPATH}/ft_atoi ${LIBPATH}/ft_memalloc
        ${LIBPATH}/ft_bzero main libft/ft_flagstr.c
        ${LIBPATH}/ft_strlen libft/ft_putnstr.c libft/ft_flagpercent.c libft/ft_flagchar.c libft/ft_strchr.c
        libft/flag_unsignedint.c libft/ft_putunsignednbr.c libft/flag_o.c libft/ft_swap.c)