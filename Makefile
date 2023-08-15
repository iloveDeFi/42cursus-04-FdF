# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 10:03:49 by bat               #+#    #+#              #
#    Updated: 2023/08/15 12:00:44 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fdf

CC      =   gcc

CFLAGS  =   -Wall -Wextra -Werror -O3 -g -fsanitize=address

SRCS := $(wildcard srcs/*.c)

INCLUDES =   includes/

OBJS    =   $(SRCS:srcs/%.c=%.o)

RM      =   rm -f

MLX     =   -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

lib:
	make -C libft/
	make -C minilibx_macos/

all:    lib $(NAME)

$(NAME):    $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCLUDES) -Llibft -lft $(MLX)

%.o: srcs/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	${RM} $(OBJS)
	@make -C libft clean
	@make -C minilibx_macos clean

fclean:     clean
	$(RM) $(NAME)
	${RM} fdf libft/libft.a
	@make -C libft fclean
	@make -C minilibx_macos fclean

re:             fclean all

.PHONY:             all  clean fclean re
