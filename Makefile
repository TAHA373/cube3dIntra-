# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 21:14:09 by tkannane          #+#    #+#              #
#    Updated: 2024/08/14 18:35:08 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -fsanitize=address -g -Wextra -Wall -Werror -Ofast
sources = ./mandatory/execution/main.c ./mandatory/execution/ray_casting.c ./mandatory/execution/render_walls.c ./mandatory/parsing/parsing.c ./mandatory/parsing/get_next_line.c ./mandatory/parsing/get_next_line_utils.c
objs = $(sources:.c=.o)
BSRC = ./bonus/execution/main.c ./bonus/execution/ray_casting.c ./bonus/execution/render_walls.c ./bonus/parsing/parsing_bonus.c ./bonus/parsing/get_next_line.c ./bonus/parsing/get_next_line_utils.c ./bonus/animation.c
BOBJ = $(BSRC:.c=.o)
NAME = cub3D
BNAME = cub3D_bonus
BONUS=bonus

all: $(NAME)

bonus : $(BNAME)



./mandatory/%.o:./mandatory/%.c ./mandatory/cub3d.h
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