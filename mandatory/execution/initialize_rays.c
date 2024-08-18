/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:09:47 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 16:59:34 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	ft_periodic(float angle)
{
	while (angle < 0)
		angle += (2 * M_PI);
	while (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	initialize_tray(t_ray *ray, float ray_angle)
{
	ray->ray_angle = ray_angle;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->ray_facing_down = 1;
	else
		ray->ray_facing_down = 0;
	if (!ray->ray_facing_down)
		ray->ray_facing_up = 1;
	else
		ray->ray_facing_up = 0;
	if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
		ray->ray_facing_right = 1;
	else
		ray->ray_facing_right = 0;
	if (!ray->ray_facing_right)
		ray->ray_facing_left = 1;
	else
		ray->ray_facing_left = 0;
	ray->distance = 0;
}

float	distance_between_points(float p_x, float p_y, float hit_x, float hit_y)
{
	return (sqrt(((hit_x - p_x) * (hit_x - p_x))
			+ ((hit_y - p_y) * (hit_y - p_y))));
}

float	ft_cheking_up(t_ray *ray, float y)
{
	if (ray->ray_facing_up)
		y--;
	return (y);
}

float	ft_cheking_left(t_ray *ray, float x)
{
	if (ray->ray_facing_left)
		x--;
	return (x);
}
