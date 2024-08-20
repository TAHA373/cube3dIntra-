/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:36:22 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/20 18:12:34 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_distance(t_ray *ray, int hit_wall, t_cube *cube)
{
	if (hit_wall)
		ray->distance = distance_between_points(cube->player->x_position,
				cube->player->y_position, ray->wall_hit_x, ray->wall_hit_y);
	else
		ray->distance = INT_MAX;
}

void	check_for_h(t_ray *ray, float x_intercept, float y_intercept,
		t_cube *cube)
{
	float	next_hor_x;
	float	next_hor_y;
	int		hit_wall;

	next_hor_x = x_intercept;
	next_hor_y = y_intercept;
	hit_wall = 0;
	while (next_hor_x >= 0 && next_hor_y >= 0
		&& next_hor_x < cube->map_width * PIXEL_SIZE
		&& next_hor_y < cube->map_height * PIXEL_SIZE)
	{
		if (!check_wall2(cube, next_hor_x, ft_cheking_up(ray, &next_hor_y)))
		{
			ray->wall_hit_x = next_hor_x;
			ray->wall_hit_y = next_hor_y;
			hit_wall = 1;
			break ;
		}
		else
		{
			next_hor_x += ray->x_step;
			next_hor_y += ray->y_step;
		}
	}
	get_distance(ray, hit_wall, cube);
}

void	check_for_v(t_ray *ray, float x_intercept, float y_intercept,
		t_cube *cube)
{
	float	next_ver_x;
	float	next_ver_y;
	int		hit_wall;

	next_ver_x = x_intercept;
	next_ver_y = y_intercept;
	hit_wall = 0;
	while (next_ver_x >= 0 && next_ver_y >= 0
		&& next_ver_x <= cube->map_width * PIXEL_SIZE
		&& next_ver_y <= cube->map_height * PIXEL_SIZE)
	{
		if (!check_wall2(cube, ft_cheking_left(ray, &next_ver_x), next_ver_y))
		{
			ray->wall_hit_x = next_ver_x;
			ray->wall_hit_y = next_ver_y;
			hit_wall = 1;
			break ;
		}
		else
		{
			next_ver_x += ray->x_step;
			next_ver_y += ray->y_step;
		}
	}
	get_distance(ray, hit_wall, cube);
}

/* HORIZONTAL RAY INTERSECTION CODE */
/* FIND THE Y COORDINATE OF THE CLOSEST HORIZONTAL GRID INTERSECTION */
/* FIND THE X COORDINATE OF THE CLOSEST HORIZONTAL GRID INTERSECTION */
/* CALCULATE THE INCREMENT X_STEP AND THE Y_STEP */

void	horizontal_ray(t_ray *ray, float ray_angle, t_cube *cube)
{
	float	y_intercept;
	float	x_intercept;

	initialize_tray(ray, ray_angle);
	y_intercept = floor(cube->player->y_position / PIXEL_SIZE) * PIXEL_SIZE;
	if (ray->ray_facing_down)
		y_intercept += PIXEL_SIZE;
	x_intercept = cube->player->x_position
		+ (y_intercept - cube->player->y_position) / tan(ray_angle);
	ray->y_step = PIXEL_SIZE;
	if (ray->ray_facing_up)
		ray->y_step *= -1;
	ray->x_step = PIXEL_SIZE / tan(ray_angle);
	if (ray->ray_facing_left && ray->x_step > 0)
		ray->x_step *= -1;
	else if (ray->ray_facing_right && ray->x_step < 0)
		ray->x_step *= -1;
	check_for_h(ray, x_intercept, y_intercept, cube);
}
/*VERTICAL RAY INTERSECTION CODE */
/* FIND THE X COORDINATE OF THE CLOSEST VERTICAL GRID INTERSECTION */
/* FIND THE Y COORDINATE OF THE CLOSEST VERTICAL GRID INTERSECTION */
/* CALCULATE THE INCREMENT X_STEP AND Y_STEP */

void	vertical_ray(t_ray *ray, float ray_angle, t_cube *cube)
{
	float	y_intercept;
	float	x_intercept;

	initialize_tray(ray, ray_angle);
	x_intercept = floor(cube->player->x_position / PIXEL_SIZE) * PIXEL_SIZE;
	if (ray->ray_facing_right)
		x_intercept += PIXEL_SIZE;
	y_intercept = cube->player->y_position
		+ (x_intercept - cube->player->x_position) * tan(ray_angle);
	ray->x_step = PIXEL_SIZE;
	if (ray->ray_facing_left)
		ray->x_step *= -1;
	ray->y_step = PIXEL_SIZE * tan(ray_angle);
	if (ray->ray_facing_up && ray->y_step > 0)
		ray->y_step *= -1;
	else if (ray->ray_facing_down && ray->y_step < 0)
		ray->y_step *= -1;
	check_for_v(ray, x_intercept, y_intercept, cube);
}
