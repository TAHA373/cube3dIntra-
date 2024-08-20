/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:14:32 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/20 18:08:23 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	ft_scale_f(float prev)
{
	float	new;

	new = (prev * 20) / PIXEL_SIZE;
	return (new);
}

void	draw_circle(mlx_image_t *img, float cx,
					float cy, int radius)
{
	float	y;
	float	x;
	int		color;

	color = ft_pixel(95, 209, 23, 255);
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				mlx_put_pixel(img, (cx + x), (cy + y), color);
			x++;
		}
		y++;
	}
}

void	clear_img_mini(mlx_image_t *image)
{
	int		x;
	int		y;

	y = 0;
	while (y < 200)
	{
		x = 0;
		while (x < 200)
		{
			mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}

void	put_the_pixel(t_cube *cube, int colors)
{
	mlx_put_pixel(cube->mini_map, cube->mini_x, cube->mini_y, colors);
}
