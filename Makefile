# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/14 16:43:40 by aoudin            #+#    #+#              #
#    Updated: 2017/01/24 14:01:35 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

SRCS = 	srcs/ft_draw.c \
	   	srcs/ft_print_map.c \
		srcs/ft_extra.c \
		srcs/ft_parse.c \
		srcs/ft_splitmap.c \
		srcs/main.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@make -s -C libs/minilibx_macos
	@echo "Minilibx Compiled"
	@$(CC) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "fdf Compiled"

all : $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@make clean -s -C libs/minilibx_macos
	@echo ".o Minilibx delete"
	@$(RM) $(OBJ)
	@echo ".o fdf delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) libs/minilibx_macos/libmlx.a
	@echo "libmlx.a delete"
	@$(RM) $(NAME)
	@echo "fdf delete"

re : fclean all
