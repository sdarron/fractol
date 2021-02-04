# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:56:39 by sdarron           #+#    #+#              #
#    Updated: 2020/02/16 14:29:37 by sdarron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FRAMEWORK = -framework OpenGL -framework AppKit

GCC = gcc

LIB = libft/libft.a minilibx_macos/libmlx.a

SRCS =	dragon.c \
		func.c \
		func1.c \
		julia.c \
		main.c \
		mandelbrot.c \
		tree.c \
		presskey.c \

FLAGS = -Wall -Wextra -Werror -O3

OBJ = $(patsubst %.c, %.o, $(SRCS))

all:	$(NAME)

$(OBJ):	$(SRCS)
		@$(GCC) $(FLAGS) -c $(SRCS)

$(NAME): $(OBJ)
		make -C ./libft/
		make -C ./minilibx_macos/
		@$(GCC) $(OBJ) $(LIB) $(FRAMEWORK) -o $(NAME)

clean:
		@/bin/rm -f $(OBJ)
		@/bin/rm -f libft/*.o
		@/bin/rm -f minilibx_macos/*.o

fclean: clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f libft/libft.a
		
re: fclean all

.PHONY: all clean fclean re