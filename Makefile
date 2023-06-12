# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 10:03:49 by bat               #+#    #+#              #
#    Updated: 2023/06/12 15:51:44 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c hooks.c start.c points.c draw.c limits.c train.c train2.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= fdf

CC		= gcc -g
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror #-fsanitize=address

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -Iprintf -I./minilibx -c $? -o $@
#		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:		${OBJS}
		@make -C libft
		@make -C printf
		@make -C minilibx
		${CC} ${CFLAGS} $^ -Llibft -lft -Lprintf -lftprintf -L./minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
#		$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libft:
		make -C libft

printf:
		make -C printf

minilibx:
		make -C minilibx

clean:
			make clean -C libft
			make clean -C printf
			make clean -C minilibx
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		libft printf