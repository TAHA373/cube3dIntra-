/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:36:18 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 18:19:52 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_wall(t_cube *cube, float new_x, float new_y)
{
	int		x;
	int		y;
	int		len;

	x = floor(new_x / PIXEL_SIZE);
	y = floor( new_y / PIXEL_SIZE);
	if (x >= cube->map_width || y >= cube->map_height || x < 0 || y < 0)
		return (0);
	len = ft_strlen(cube->map[y]);
	if (x >= len)
		return (0);  
	if (cube->map[y][x] == '1'  || cube->map[y][x] == ' ')
		return (0);
	return (1);
}

int	arround_player(t_cube *cube, float new_x, float new_y)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 360)
	{
		x = new_x +  cos(i * MATH_PI / 180) * 200;
		y = new_y +  sin(i * MATH_PI / 180) * 200;
		if (!check_wall(cube, x, y) || !check_wall(cube, new_x, new_y))
			break ;
		i++;
	}
	if (i != 360)
		return (0);
	return (1);
}

void	update_player_place(t_cube *cube)
{
	int		move_step;
	float	new_x;
	float	new_y;

	move_step = 0;
	new_x = 0;
	new_y = 0;
	cube->player->rotation_angle += cube->player->player_rotation_speed
		* cube->player->l_r_directions;
	cube->player->rotation_angle = ft_periodic(cube->player->rotation_angle);
	move_step = cube->player->b_f_directions * cube->player->player_move_speed;
	new_x = cube->player->x_position + cos(cube->player->rotation_angle)
		* move_step;
	new_y = cube->player->y_position + sin(cube->player->rotation_angle)
		* move_step;
	if (arround_player(cube, new_x, new_y))
	{
		cube->player->x_position = new_x;
		cube->player->y_position = new_y;
	}
	ft_release(cube);
}

void	update_player_place_left(t_cube *cube)
{
	float	new_x;
	float	new_y;

	new_x = cube->player->x_position
		+ cos(cube->player->rotation_angle - M_PI / 2)
		* cube->player->player_move_speed;
	new_y = cube->player->y_position
		+ sin(cube->player->rotation_angle - M_PI / 2)
		* cube->player->player_move_speed;
	if (arround_player(cube, new_x, new_y))
	{
		cube->player->x_position = new_x;
		cube->player->y_position = new_y;
	}
	ft_release(cube);
}

void	update_player_place_right(t_cube *cube)
{
	float	new_x;
	float	new_y;

	new_x = cube->player->x_position
		+ cos(cube->player->rotation_angle + M_PI / 2)
		* cube->player->player_move_speed;
	new_y = cube->player->y_position
		+ sin(cube->player->rotation_angle + M_PI / 2)
		* cube->player->player_move_speed;
	if (arround_player(cube, new_x, new_y))
	{
		cube->player->x_position = new_x;
		cube->player->y_position = new_y;
	}
	ft_release(cube);
}