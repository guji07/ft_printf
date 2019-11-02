SRCS = flag_unsignedint.c  ft_flagf.c          ft_flagx.c        ft_memalloc.c  ft_putnstr.c    ft_reverse.c         ft_strlen.c \
       ft_atoi.c           ft_flagp.c          ft_intlen.c       ft_printf.c    ft_putstr.c     ft_strchr.c          ft_swap.c     parsers.c \
       flag_int.c          ft_bzero.c          ft_flagpercent.c  ft_itoabase.c  ft_putchar.c    ft_putunsignednbr.c  ft_strequ.c   ft_unsignedintlen.c \
       flag_o.c            ft_flagchar.c       ft_flagstr.c      ft_max.c       ft_putnbrpos.c  ft_putupstr.c        ft_strjoin.c  ft_write.c \

OBJECTS	= flag_unsignedint.o  ft_flagf.o          ft_flagx.o        ft_memalloc.o  ft_putnstr.o    ft_reverse.o         ft_strlen.o \
          ft_atoi.o           ft_flagp.o          ft_intlen.o       ft_printf.o    ft_putstr.o     ft_strchr.o          ft_swap.o     parsers.o \
          flag_int.o          ft_bzero.o          ft_flagpercent.o  ft_itoabase.o  ft_putchar.o    ft_putunsignednbr.o  ft_strequ.o   ft_unsignedintlen.o \
          flag_o.o            ft_flagchar.o       ft_flagstr.o      ft_max.o       ft_putnbrpos.o  ft_putupstr.o        ft_strjoin.o  ft_write.o \
HEADER = libft.h
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
