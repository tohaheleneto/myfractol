 

C = gcc

NAME = fractol

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = sources

DIR_O = temporary

DIR_MLX = minilibx

HEADERS = includes


all: temporary $(NAME)

$(NAME): $(OBJS)
	#@make -C $(LIBFT)
	#@make -C $(DIR_MLX)
	@$(CC) -L $(LIBFT) -lft  main.c -L $(DIR_MLX) -lm -lmlx -framework OpenGL -framework AppKit 

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

norme:
	@make norme -C $(LIBFT)
	@echo
	norminette ./$(HEADERS)
	@echo
	norminette ./$(DIR_S)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(DIR_MLX)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(DIR_MLX)

re: fclean all

.PHONY: all, temporary, norme, clean, fclean, re
