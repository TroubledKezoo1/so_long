# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:21:17 by ysarac            #+#    #+#              #
#    Updated: 2024/03/08 09:36:52 by ysarac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC = ft_printf.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)

c:clean
clean:
	@$(RM) $(OBJ)

fc:fclean	
fclean: clean
	@$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
