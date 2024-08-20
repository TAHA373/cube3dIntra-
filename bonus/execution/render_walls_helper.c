/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:36:29 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/19 23:04:33 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_getoff_x(t_cube *cube, t_ray *ray)
{
	if (ray->is_ver)
		cube->player->offset_x = (int)ray->wall_hit_y % PIXEL_SIZE;
	else
		cube->player->offset_x = (int)ray->wall_hit_x % PIXEL_SIZE;
}

void	draw_ceiling(t_cube *cube, int x, int wall_top)
{
	int	y;

	y = -1;
	while (++y < wall_top)
		mlx_put_pixel(cube->image, x, y, ft_pixel(cube->data->carr[0],
				cube->data->carr[1], cube->data->carr[2], 255));
}

void	draw_floor(t_cube *cube, int x, int wall_bottom)
{
	int	y;

	y = wall_bottom - 1;
	while (++y < WIN_HEIGHT)
		mlx_put_pixel(cube->image, x, y, ft_pixel(cube->data->farr[0],
				cube->data->farr[1], cube->data->farr[2], 255));
}
