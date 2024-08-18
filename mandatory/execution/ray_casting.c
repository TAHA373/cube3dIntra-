/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:12:49 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 16:57:04 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
