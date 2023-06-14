# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 10:03:49 by bat               #+#    #+#              #
#    Updated: 2023/06/14 14:16:16 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=			fdf.c \
					error_and_free.c \
					parsing.c \
					convert.c \
					graphic.c \
					draw.c \
					hooks.c \
					colors.c \

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w

NAME	=			fdf

all: 				$(NAME)

%.o: 				%.c
					${CC} ${CFLAGS} -Ilibft -I./minilibx -c $? -o $@

${NAME}:			${OBJS}
					@make -C libft
					@make -C minilibx
					${CC} ${CFLAGS} $^ -Llibft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

libft/libft.a:
					@make -C libft

minilibx/libmlx.a:
					@make -C minilibx

clean:
					${RM} $(OBJS)
					@make -C libft clean
					@make -C minilibx clean

fclean:				clean
					${RM} fdf libft/libft.a
					@make -C libft fclean
					@make -C minilibx fclean

re: 				fclean all

.PHONY:				all  clean fclean re