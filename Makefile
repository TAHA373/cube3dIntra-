# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 21:14:09 by tkannane          #+#    #+#              #
#    Updated: 2024/08/19 02:20:41 by soel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -Wextra -Wall -Werror -Ofast
sources = ./mandatory/execution/main.c ./mandatory/execution/ray_casting.c ./mandatory/execution/render_walls.c\
		./mandatory/parsing/parsing.c ./mandatory/parsing/get_next_line.c ./mandatory/parsing/get_next_line_utils.c\
		./mandatory/parsing/parsmap.c ./mandatory/parsing/parsmap2.c ./mandatory/parsing/errors.c ./mandatory/parsing/parscolors.c\
		./mandatory/parsing/parsinfos.c ./mandatory/parsing/parstexters.c ./mandatory/parsing/gettexters.c\
		./mandatory/execution/initialize.c ./mandatory/execution/key_press.c ./mandatory/execution/player_place.c\
		./mandatory/execution/texture_image.c ./mandatory/execution/render_walls_helper.c ./mandatory/execution/ray_casting_helper.c\
		./mandatory/execution/initialize_rays.c
objs = $(sources:.c=.o)
BSRC =	 ./bonus/parsing/parsing_bonus.c ./bonus/parsing/get_next_line.c ./bonus/parsing/get_next_line_utils.c\
		bonus/parsing/parsmap.c bonus/parsing/parsmap2.c bonus/parsing/errors.c bonus/parsing/parscolors.c\
		bonus/parsing/parsinfos.c bonus/parsing/parstexters.c bonus/parsing/gettexters.c\
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