define HEADER
    __             
   (       /      _ 
   __)()__(__()/)(/ 
                _/  

endef
export HEADER

NAME		= so_long

SRCS		= $(wildcard srcs/*.c)

OBJS		= $(SRCS:%.c=%.o)

LIBFTA		= ./libft/libft.a

MLX		= ./mlx/libmlx.a

MLX_FLAGS	= -framework OpenGL -framework AppKit

LINKS		= -L mlx -lmlx -L libft

INCLUDES	= -I mlx -I libft -I .

CC		= gcc -Wall -Wextra -g -fsanitize=address -Werror

RM		= rm -f

ARGS	= map.ber

.c.o:
			$(CC) -c $< -o $@


all:		$(NAME)

$(NAME): 	 $(MLX) $(LIBFTA) $(OBJS)
			$(CC) $(MLX) $(LIBFTA) $(MLX_FLAGS) $(OBJS) -o $(NAME)
			clear
			@ echo "$${HEADER}"
			@echo "$(GREEN)Successfully built"


$(MLX):
			make -C mlx

# $(LIBFTA):
# 			make -C libft
run:    ${NAME}
		./${NAME} ${ARGS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C mlx clean
			@echo "$(RED)Files Removed!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean re fclean

#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m
