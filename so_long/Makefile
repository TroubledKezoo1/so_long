NAME				=	so_long

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
AR					=	ar
ARFLAGS 			=	rcs
RM					=	rm -rf

SRC					=	so_long.c \
						game_first_control.c \
						maps_first_control.c \
						game_second_control.c \
						maps_second_control.c \
						free.c \
						get_next_line/get_next_line.c \
						get_next_line/get_next_line_utils.c\
						
LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a

PRINTF_PATH			= ./ft_printf
PRINTF				= $(PRINTF_PATH)/libftprintf.a

MINILIBX_PATH		=	./minilibx

all:				$(NAME)

$(NAME):			$(LIBFT) $(PRINTF) mlx
					@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(PRINTF) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

$(LIBFT):
					@make -C $(LIBFT_PATH) all

$(PRINTF):
					@make -C $(PRINTF_PATH) all

mlx:
					@make -C $(MINILIBX_PATH) all

clean:
					@make -C $(PRINTF_PATH) clean
					@make -C $(LIBFT_PATH) clean
					@make -C $(MINILIBX_PATH) clean

fclean:				clean
					@make -C $(PRINTF_PATH) fclean
					@make -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME)

re:					fclean all

norm:
					@norminette $(SRC) $(LIBFT_PATH) $(PRINTF_PATH) so_long.h

.PHONY:				all clean fclean re libft