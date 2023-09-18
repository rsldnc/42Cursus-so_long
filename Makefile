SRCS = checkers.c control_ops.c graphic_ops.c graphic_ops2.c map_checkers.c map_checkers2.c map_ops.c so_long.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = so_long
FT_PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a
LFLAGS = -framework AppKit -framework OpenGL -Lminilibx -lmlx
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX)
	gcc $(CFLAGS) $(LFLAGS) -o so_long $(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX)

$(FT_PRINTF):
	@make -C ft_printf

$(LIBFT):
	@make -C libft

$(MINILIBX):
	@make -C minilibx

clean:
	rm -rf *.o
	@make -C ft_printf clean
	@make -C libft clean

fclean: clean
	rm -rf so_long
	@make -C ft_printf fclean
	@make -C libft fclean
	@make -C minilibx clean

re: fclean all

.PHONY: all clean fclean re