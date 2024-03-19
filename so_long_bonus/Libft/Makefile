# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysarac <yunusemresarac@yaani.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 23:10:39 by ysarac            #+#    #+#              #
#    Updated: 2023/10/24 23:38:58 by ysarac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar -rc

SRC 	=   ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_strlen.c \
			ft_bzero.c \
			ft_strdup.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_memmove.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c

B_SRC 	= 	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ		= $(SRC:%.c=%.o)

B_OBJ	= $(B_SRC:%.c=%.o)

$(NAME): 
	@$(CC) $(FLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)     
all: $(NAME)

bonus:
	@$(CC) $(FLAGS) -c $(B_SRC)
	@$(AR) $(NAME) $(B_OBJ)
c:clean
clean:
	@$(RM) $(OBJ)
f:fclean
fc:fclean
fclean:
	@$(RM) $(OBJ) $(NAME) a.out

re: fclean all

.PHONY: all bonus clean fclean re 
