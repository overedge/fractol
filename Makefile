SRC_NAME = main.c init.c input.c draw.c input2.c draw2.c

NAME = fractol

OBJ_NAME = $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	@make fclean -C libft/ && make -C libft/ 
	@make -C mlx/ clean && make -C mlx/
	@cp libft/libft.a .
	@cp mlx/libmlx.a .
	@gcc -c -Wall -Werror -Wextra $(SRC_NAME)
	@gcc $(OBJ_NAME) -o $(NAME) -L. -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;34m --fractol-- :\033[m \033[1;32m DONE !\033[m"


clean :
	@rm -rf $(OBJ_NAME)
	@rm -rf libft.a
	@make clean -C libft/
	@make clean -C mlx/
	@echo "\033[1;34m --fractol-- :\033[m \033[1;32m DELETE OBJ FILES !\033[m"
	@rm -rf libmlx.a

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@echo "\033[1;34m --fractol-- :\033[m \033[1;32m DELETE project !\033[m"

re : fclean all

.PHONY : all re clean fclean
