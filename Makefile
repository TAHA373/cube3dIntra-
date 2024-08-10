# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 21:14:09 by tkannane          #+#    #+#              #
#    Updated: 2024/08/09 23:49:48 by soel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -fsanitize=address -g -Wextra -Wall -Werror -Ofast
sources = ./execution/main.c ./execution/ray_casting.c ./execution/render_walls.c ./parsing/parsing.c ./parsing/get_next_line.c ./parsing/get_next_line_utils.c animation.c
objs = $(sources:.c=.o)
BSRC = ./bonus/execution/main.c ./bonus/execution/ray_casting.c ./bonus/execution/render_walls.c ./bonus/parsing/parsing_bonus.c ./bonus/parsing/get_next_line.c ./bonus/parsing/get_next_line_utils.c ./bonus/animation.c
BOBJ = $(BSRC:.c=.o)
NAME = cub3D
BNAME = cub3D_bonus
BONUS=bonus

all: $(NAME)

bonus : $(BNAME)



%.o:%.c cub3d.h
	$(cmd) $(cflags) -c $< -o $@

$(BONUS)/%.o:$(BONUS)/%.c $(BONUS)/cub3d_bonus.h
	$(cmd) $(cflags) -c $< -o $@

$(NAME): $(objs)
		make -C libft
		$(cmd) $(cflags) $(objs) -o $@ MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" libft/libft.a

$(BNAME): $(BOBJ)
		make -C libft
		$(cmd) $(cflags) $(BOBJ) -o $@ MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" libft/libft.a

clean:
		make -C libft clean
		rm -rf $(objs)
		rm -rf $(BOBJ)

fclean:	clean
		make -C libft fclean
		rm -rf $(NAME)
		rm -rf $(BNAME)

re:	fclean all