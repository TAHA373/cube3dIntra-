# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 21:14:09 by tkannane          #+#    #+#              #
#    Updated: 2024/07/27 00:25:26 by soel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -fsanitize=address -g -Wextra -Wall -Werror
sources = ./execution/main.c ./execution/ray_casting.c ./execution/render_walls.c ./parsing/parsing.c ./parsing/get_next_line.c ./parsing/get_next_line_utils.c
objs = $(sources:.c=.o)
NAME = cube3D

all: $(NAME)

%.o:%.c cub3d.h
	$(cmd) $(cflags) -c $< -o $@

$(NAME): $(objs)
		make -C libft
		$(cmd) $(cflags) $(objs) -o $@ MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" libft/libft.a

clean:
		make -C libft clean
		rm -rf $(objs)

fclean:	clean
		make -C libft fclean
		rm -rf $(NAME)

re:	fclean all