/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:10:01 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/20 18:11:43 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_colors_w_e(t_ray *ray, t_cube *cube, int j)
{
	if (ray->is_ver && ray->content == '1')
	{
		if (ray->ray_facing_left)
		{
			ray->colors.r = cube->west->pixels[j];
			ray->colors.g = cube->west->pixels[j + 1];
			ray->colors.b = cube->west->pixels[j + 2];
			ray->colors.a = cube->west->pixels[j + 3];
		}
		else
		{
			ray->colors.r = cube->east->pixels[j];
			ray->colors.g = cube->east->pixels[j + 1];
			ray->colors.b = cube->east->pixels[j + 2];
			ray->colors.a = cube->east->pixels[j + 3];
		}
	}
}

void	get_colors_n_s(t_ray *ray, t_cube *cube, int j)
{
	if (!ray->is_ver && ray->content == '1')
	{
		if (ray->ray_facing_down)
		{
			ray->colors.r = cube->south->pixels[j];
			ray->colors.g = cube->south->pixels[j + 1];
			ray->colors.b = cube->south->pixels[j + 2];
			ray->colors.a = cube->south->pixels[j + 3];
		}
		else
		{
			ray->colors.r = cube->north->pixels[j];
			ray->colors.g = cube->north->pixels[j + 1];
			ray->colors.b = cube->north->pixels[j + 2];
			ray->colors.a = cube->north->pixels[j + 3];
		}
	}
}
// Calculate the distance to the projection plane /*Project wall height*/
/*Calculate the top and bottom of the wall strip*/
/*Calculate the top and bottom of the wall strip*/

void	calculate_wall_height(t_ray *ray, t_cube *cube)
{
	ray->raydistance = ray->distance * cos(ft_periodic(ray->ray_angle)
			- cube->player->rotation_angle);
	ray->distance_project = (WIN_WIDTH / 2) / tan(FOV / 2);
	ray->wall_striph = (PIXEL_SIZE / ray->raydistance) * ray->distance_project;
	ray->wall_top = (WIN_HEIGHT / 2) - (ray->wall_striph / 2);
	ray->wall_bottom = (WIN_HEIGHT / 2) + (ray->wall_striph / 2);
}

void	draw_door(t_ray *ray, t_cube *cube, int j)
{
	if (ray->content == 'D')
	{
		ray->colors.r = cube->i_door->pixels[j];
		ray->colors.g = cube->i_door->pixels[j + 1];
		ray->colors.b = cube->i_door->pixels[j + 2];
		ray->colors.a = cube->i_door->pixels[j + 3];
	}
}

void	render_wall(t_ray *ray, t_cube *cube, int i)
{
	int	y;
	int	dis;
	int	j;

	calculate_wall_height(ray, cube);
	draw_ceiling(cube, i, ray->wall_top);
	if (ray->wall_top < 0)
		ray->wall_top = 0;
	if (ray->wall_bottom >= WIN_HEIGHT)
		ray->wall_bottom = WIN_HEIGHT - 1;
	ft_getoff_x(cube, ray);
	y = ray->wall_top;
	while (y < ray->wall_bottom)
	{
		dis = y - WIN_HEIGHT / 2 + ray->wall_striph / 2;
		cube->player->offset_y = dis * ((float)PIXEL_SIZE / ray->wall_striph);
		j = (cube->player->offset_x + cube->player->offset_y * PIXEL_SIZE) * 4;
		get_colors_w_e(ray, cube, j);
		get_colors_n_s(ray, cube, j);
		draw_door(ray, cube, j);
		mlx_put_pixel(cube->image, i, y, ft_pixel(ray->colors.r, ray->colors.g,
				ray->colors.b, ray->colors.a * exp(-0.00007 * ray->distance)));
		y++;
	}
	draw_floor(cube, i, ray->wall_bottom);
}
