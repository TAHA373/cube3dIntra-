# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 21:14:09 by tkannane          #+#    #+#              #
#    Updated: 2024/08/18 18:16:19 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -g -fsanitize=address -Wextra -Wall -Werror -Ofast
sources = ./mandatory/execution/main.c ./mandatory/execution/ray_casting.c ./mandatory/execution/render_walls.c ./mandatory/parsing/parsing.c ./mandatory/parsing/get_next_line.c ./mandatory/parsing/get_next_line_utils.c ./mandatory/parsing/parsmap.c  ./mandatory/parsing/parscolors.c ./mandatory/parsing/parsinfos.c ./mandatory/parsing/parstexters.c ./mandatory/parsing/gettexters.c ./mandatory/execution/initialize.c ./mandatory/execution/key_press.c ./mandatory/execution/player_place.c ./mandatory/execution/texture_image.c ./mandatory/execution/render_walls_helper.c ./mandatory/execution/ray_casting_helper.c ./mandatory/execution/initialize_rays.c
objs = $(sources:.c=.o)
BSRC =	 ./bonus/parsing/parsing_bonus.c ./bonus/parsing/get_next_line.c ./bonus/parsing/get_next_line_utils.c\
		bonus/execution/initialize_rays.c bonus/execution/initialize.c bonus/execution/key_press.c bonus/execution/main.c\
		bonus/execution/mini_map.c bonus/execution/player_place.c bonus/execution/ray_casting_helper.c bonus/execution/ray_casting.c\
		bonus/execution/render_walls_helper.c bonus/execution/render_walls.c bonus/execution/texture_image.c bonus/animation.c bonus/mouse.c
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