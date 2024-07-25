# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 21:14:09 by tkannane          #+#    #+#              #
#    Updated: 2024/07/24 13:20:44 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -fsanitize=address -g -Wextra -Wall -Werror
sources = main.c ray_casting.c render_walls.c 
objs = $(sources:.c=.o)
NAME = cube3D

all: $(NAME)

%.o:%.c execution.h
	$(cmd) $(cflags) -c $< -o $@

$(NAME): $(objs)
		$(cmd) $(cflags) $(objs) -o $@ ../MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

clean:
		rm -rf $(objs)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all