/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:36:38 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/21 18:29:02 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
	if (cube->t_door)
		mlx_delete_texture(cube->t_door);
}

void	image_delete(t_cube *cube)
{
	if (cube->i_door)
		mlx_delete_image(cube->mlx_win, cube->i_door);
	if (cube->south)
		mlx_delete_image(cube->mlx_win, cube->south);
	if (cube->east)
		mlx_delete_image(cube->mlx_win, cube->east);
	if (cube->west)
		mlx_delete_image(cube->mlx_win, cube->west);
	if (cube->north)
		mlx_delete_image(cube->mlx_win, cube->north);
	if (cube->i_door)
		mlx_delete_image(cube->mlx_win, cube->i_door);
}
