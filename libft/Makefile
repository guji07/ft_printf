SRCS = flag_char.c	flag_f2.c	flag_o.c	flag_percent.c	flag_unsignedint.c	ft_atoi.c		ft_flagx2.c    \
	   ft_itoabase.c	ft_memalloc.c	ft_putchar.c	ft_putnstr.c	ft_putunsignednbr.c		ft_reverse.c   \
	   ft_strequ.c	ft_strjoinfree.c	ft_swap.c      	ft_write.c		parsers.c	flag_f1.c	flag_int.c     \
	   flag_p.c		flag_str.c	flag_x1.c	ft_bzero.c	ft_intlen.c		ft_max.c	ft_printf.c	ft_putnbrpos.c \
	   ft_putstr.c  ft_putupstr.c ft_strchr.c ft_strjoin.c ft_strlen.c  ft_unsignedintlen.c                    \

OBJECTS	= flag_char.o	flag_f2.o	flag_o.o	flag_percent.o	flag_unsignedint.o	ft_atoi.o		ft_flagx2.o    \
          ft_itoabase.o	ft_memalloc.o	ft_putchar.o	ft_putnstr.o	ft_putunsignednbr.o		ft_reverse.o   \
          ft_strequ.o	ft_strjoinfree.o	ft_swap.o      	ft_write.o		parsers.o	flag_f1.o	flag_int.o     \
          flag_p.o		flag_str.o	flag_x1.o	ft_bzero.o	ft_intlen.o		ft_max.o	ft_printf.o	ft_putnbrpos.o \
          ft_putstr.o  ft_putupstr.o ft_strchr.o ft_strjoin.o ft_strlen.o  ft_unsignedintlen.o                    \

HEADER = libftprintf.h
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
all: $(NAME)
$(NAME):$(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo libftprintf compiled
%.o: %.c $(HEADER)
	@gcc -I . $(FLAGS) $< -c -o $@
clean:
	@rm -f $(OBJECTS)
	@echo .o cleaned
fclean: clean
	@rm -rf $(NAME)
	@echo libftprintf.a cleaned
re: fclean all
.PHONY: clean fclean re
