/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:52:52 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/22 01:08:35 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear_image(mlx_image_t *image)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}

void	textures_delete(t_cube *cube)
{
	if (cube->data->south)
		mlx_delete_texture(cube->data->south);
	if (cube->data->east)
		mlx_delete_texture(cube->data->east);
	if (cube->data->west)
		mlx_delete_texture(cube->data->west);
	if (cube->data->north)
		mlx_delete_texture(cube->data->north);
}

void	image_delete(t_cube *cube)
{
	if (cube->south && cube->mlx_win)
	{
		mlx_delete_image(cube->mlx_win, cube->south);
		cube->south = NULL;
	}
	if (cube->east && cube->mlx_win)
	{
		mlx_delete_image(cube->mlx_win, cube->east);
		cube->east = NULL;
	}
	if (cube->west && cube->mlx_win)
	{
		mlx_delete_image(cube->mlx_win, cube->west);
		cube->west = NULL;
	}
	if (cube->north && cube->mlx_win)
	{
		mlx_delete_image(cube->mlx_win, cube->north);
		cube->north = NULL;
	}
}
