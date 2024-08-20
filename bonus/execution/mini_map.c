/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:38:42 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/20 18:09:45 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	mini_map2(t_cube *cube)
{
	if (cube->map[cube->i][cube->j] == '0' ||
		cube->map[cube->i][cube->j] == ' ' ||
		cube->map[cube->i][cube->j] == 'W' ||
		cube->map[cube->i][cube->j] == 'E' ||
		cube->map[cube->i][cube->j] == 'N' ||
		cube->map[cube->i][cube->j] == 'S')
		mlx_put_pixel(cube->mini_map, cube->mini_x,
			cube->mini_y, ft_pixel(0, 0, 0, 255));
	else if (cube->map[cube->i][cube->j] == '1')
		mlx_put_pixel(cube->mini_map, cube->mini_x,
			cube->mini_y, ft_pixel(255, 255, 255, 255));
	else if (cube->map[cube->i][cube->j] == 'D')
		mlx_put_pixel(cube->mini_map, cube->mini_x,
			cube->mini_y, ft_pixel(150, 255, 255, 255));
}

void	mini_map3(t_cube *cube)
{
	if (cube->mini_x_p >= 0 && cube->mini_y_p >= 0
		&& cube->mini_x_p < cube->map_width * 20
		&& cube->mini_y_p < cube->map_height * 20)
	{
		cube->i = cube->mini_y_p / 20;
		cube->j = cube->mini_x_p / 20;
		if (cube->j < (int)ft_strlen(cube->map[cube->i]))
			mini_map2(cube);
	}
}

float	get_distance_to_center(t_cube *cube, int radius)
{
	return ((cube->mini_x - radius) *(cube->mini_x - radius)
		+ (cube->mini_y - radius) *(cube->mini_y - radius));
}

int	ft_check(float distance_to_center, int radius)
{
	if (distance_to_center <= radius * radius
		&& distance_to_center >= (radius - 1) * (radius - 1))
		return (1);
	return (0);
}

void	mini_map(t_cube *cube)
{
	int		radius;
	float	distance_to_center;

	radius = 100;
	cube->mini_y = -1;
	cube->mini_y_p = ft_scale_f(cube->player->y_position) - radius;
	while (++cube->mini_y < 200)
	{
		cube->mini_x = -1;
		cube->mini_x_p = ft_scale_f(cube->player->x_position) - radius;
		while (++cube->mini_x < 200)
		{
			distance_to_center = get_distance_to_center(cube, radius);
			if (ft_check(distance_to_center, radius))
				put_the_pixel(cube, ft_pixel(255, 0, 0, 255));
			else if (distance_to_center < radius * radius)
				mini_map3(cube);
			cube->mini_x_p++;
		}
		cube->mini_y_p++;
	}
}
