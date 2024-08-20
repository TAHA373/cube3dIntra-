/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:36:08 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/20 15:20:49 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	initialize_data(t_map_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->ea_path = NULL;
	data->we_path = NULL;
	data->c_color = NULL;
	data->f_color = NULL;
	data->map = NULL;
	data->cub_map = NULL;
	data->east = NULL;
	data->west = NULL;
	data->north = NULL;
	data->south = NULL;
}
/***** Obtenir map width et map heigth ******/

void	get_map_h_w(t_cube *cube)
{
	int		i;
	int		width;

	i = 0;
	width = ft_strlen(cube->map[0]);
	while (cube->map[i])
	{
		if (width < (int)ft_strlen(cube->map[i]))
			width = ft_strlen(cube->map[i]);
		i++;
	}
	cube->map_height = i;
	cube->map_width = width;
}

void	initialize_cube(t_cube *cube, t_map_data *data, t_player *player)
{
	cube->data = data;
	if (data->direction == 'S')
		player->rotation_angle = MATH_PI / 2;
	else if (data->direction == 'N')
		player->rotation_angle = 3 * MATH_PI / 2;
	else if (data->direction == 'W')
		player->rotation_angle = MATH_PI;
	else
		player->rotation_angle = 2 * MATH_PI;
	player->x_position = data->x * PIXEL_SIZE + PIXEL_SIZE / 2;
	player->y_position = data->y * PIXEL_SIZE + PIXEL_SIZE / 2;
	player->radius = 5;
	player->l_r_directions = 0;
	player->b_f_directions = 0;
	player->player_move_speed = 180;
	player->player_rotation_speed = 2 * (MATH_PI / 180);
	cube->player = player;
	cube->map = data->cub_map;
	get_map_h_w(cube);
}

int	mlx_initialize(t_cube *cube)
{
	cube->mlx_win = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", false);
	if (!(cube->mlx_win))
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	cube->image = mlx_new_image(cube->mlx_win, WIN_WIDTH, WIN_HEIGHT);
	if (!(cube->image))
	{
		mlx_close_window(cube->mlx_win);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(cube->mlx_win, cube->image, 0, 0) == -1)
	{
		mlx_close_window(cube->mlx_win);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	cube->mini_map = mlx_new_image(cube->mlx_win, 200, 200);
	if (!(cube->mini_map))
		return (mlx_close_window(cube->mlx_win),
			puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	if (mlx_image_to_window(cube->mlx_win, cube->mini_map, 0, 0) == -1)
		return (mlx_close_window(cube->mlx_win),
			puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	initialize_image(t_cube *cube)
{
	cube->t_door = mlx_load_png("d.png");
	cube->i_door = mlx_texture_to_image(cube->mlx_win, cube->t_door);
	cube->isfacingdoor = false;
	cube->door_x = -1;
	cube->door_y = -1;
	cube->south = mlx_texture_to_image(cube->mlx_win, cube->data->south);
	cube->east = mlx_texture_to_image(cube->mlx_win, cube->data->east);
	cube->west = mlx_texture_to_image(cube->mlx_win, cube->data->west);
	cube->north = mlx_texture_to_image(cube->mlx_win, cube->data->north);
	textures_delete(cube);
}
