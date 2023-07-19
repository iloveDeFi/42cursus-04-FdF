# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 10:03:49 by bat               #+#    #+#              #
#    Updated: 2023/07/19 18:12:18 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fdf

CC 		= 	gcc

CFLAGS	=			-Wall -Wextra -Werror #-g -fsanitize=address

SRCS	=			fdf.c \
					error_and_free.c \
					parsing.c \
					convert.c \
					graphic.c \
					draw.c \
					hooks.c \
					colors.c \

INCLUDES = 	includes/

INCLUDES_PATH	=	/fdf/includes

OBJS		=	$(SRCS:.c=.o)

MLX		= 	-L ./minilibx -l mlx -framework OpenGL -framework AppKit

lib:
	make -C libft/
	make -C minilibx/
	make -C srcs/

all:	lib $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) libft/libft.a $(OBJS) -I $(INCLUDES) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJS) && make -C libft/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean

re: 				fclean all

.PHONY:				all  clean fclean re