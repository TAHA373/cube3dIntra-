/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:12:49 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 18:28:24 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void checkhit(t_ray *ray, t_cube *cube)
{
	int	x;
	int	y;

	x = ray->wall_hit_x / PIXEL_SIZE;
	y = ray->wall_hit_y / PIXEL_SIZE;
	if (cube->map[y][x] == '1')
	{
		ray->content = '1';
	}
	else if (cube->map[y][x] == 'D')
		ray->content = 'D';
}

int	check_wall2(t_cube *cube, float new_x, float new_y)
{
	int		x;
	int		y;
	int		len;

	x = floor(new_x / PIXEL_SIZE);
	y = floor(new_y / PIXEL_SIZE);
	if (x >= cube->map_width || y >= cube->map_height || x < 0 || y < 0)
		return (0);
	len = ft_strlen(cube->map[y]);
	if (x >= len)
		return (0);
	if (cube->map[y][x] == '1' || cube->map[y][x] == ' '
			|| (cube->map[y][x] == 'D'))
		return (0); 
	return (1);
}

void	get_final_ray_cordonate(t_ray *final_ray, t_ray *ray_v_or_h)
{
	final_ray->ray_angle = ray_v_or_h->ray_angle;
	final_ray->wall_hit_x = ray_v_or_h->wall_hit_x;
	final_ray->wall_hit_y = ray_v_or_h->wall_hit_y;
	final_ray->distance = ray_v_or_h->distance;
	final_ray->ray_facing_down = ray_v_or_h->ray_facing_down;
	final_ray->ray_facing_up = ray_v_or_h->ray_facing_up;
	final_ray->ray_facing_left = ray_v_or_h->ray_facing_left;
	final_ray->ray_facing_right = ray_v_or_h->ray_facing_right;
}
void	cast_the_ray(t_cube *cube, float ray_angle, int i)
{
	t_ray	ray_horizontal;
	t_ray	ray_vertical;
	t_ray	final_ray;

	horizontal_ray(&ray_horizontal, ray_angle, cube);
	vertical_ray(&ray_vertical, ray_angle, cube);
	if (ray_horizontal.distance < ray_vertical.distance)
	{
		get_final_ray_cordonate(&final_ray, &ray_horizontal);
		final_ray.is_ver = 0;
	}
	else
	{
		get_final_ray_cordonate(&final_ray, &ray_vertical);
		final_ray.is_ver = 1;
	}
	checkhit(&final_ray, cube);
	render_wall(&final_ray, cube, i);
}

void	cast_rays(t_cube *cube)
{
	float	ray_angle;
	float	limit_angle;
	int		i;

	i = 0;
	ray_angle = cube->player->rotation_angle - (FOV / 2);
	ray_angle = ft_periodic(ray_angle);
	limit_angle = cube->player->rotation_angle + (FOV / 2);
	limit_angle = ft_periodic(limit_angle);
	while (i < WIN_WIDTH)
	{
		ray_angle = ft_periodic(ray_angle);
		cast_the_ray(cube, ray_angle, i);
		ray_angle += FOV / WIN_WIDTH;
		i++;
	}
}

