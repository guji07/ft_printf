SRCS =   main.c

NAME = test
all: $(NAME)
$(NAME):$(OBJECTS)
	@make -C libft/ all
	@gcc $(FLAGS) main.c -L libft/ -lft
	@echo test compiled

re: fclean all
.PHONY: clean fclean re
