cmd = cc
#cflags = -Wextra -Wall -Werror
sources = main.c ray_casting.c render_walls.c
objs = $(sources:.c=.o)
NAME = cub3D

all: $(NAME)

%.o:%.c 
	$(CC) -Wall -Wextra -Werror ../MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -c $< -o $@

$(NAME): $(objs)
		$(cmd) $(cflags) $(objs) ../MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm  -o $@

clean:
		rm -rf $(objs)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all