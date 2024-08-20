/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:13:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/20 18:04:48 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	openthenooor(t_cube *data)
{
	int			player_x;
	int			player_y;
	static int	x;
	static int	y;

	player_x = (int)((data->player->x_position) / PIXEL_SIZE);
	player_y = (int)((data->player->y_position) / PIXEL_SIZE);
	if (data->map[player_y][player_x] == 'D')
	{
		x = player_x;
		y = player_y;
		data->map[player_y][player_x] = 'C';
	}
	else if (player_y != y || player_x != x)
	{
		data->map[y][x] = 'D';
	}
}

mlx_image_t	*get_frame(t_cube *data, char *type, int i)
{
	char			src[20];
	mlx_texture_t	*txt;
	char			*num;

	if (data->frame)
		mlx_delete_image(data->mlx_win, data->frame);
	ft_strlcpy(src, type, sizeof(src));
	num = ft_itoa(i + 1);
	ft_strlcat(src, num, sizeof(src));
	free(num);
	num = NULL;
	ft_strlcat(src, ".png", sizeof(src));
	txt = mlx_load_png(src);
	if (!txt)
		return (NULL);
	return (mlx_texture_to_image(data->mlx_win, txt));
}

void	hold_gun(t_cube *data)
{
	static int	count;
	static int	i;
	static bool	max;

	if (count == 2)
	{
		count = 0;
		data->frame = get_frame(data, "hold/", i);
		if (!data->frame)
			return ;
		mlx_image_to_window(data->mlx_win, data->frame, 0, 0);
		if (!max)
		{
			i++;
			if (i == 7)
				max = true;
		}
		if (max)
		{
			i--;
			if (i == 0)
				max = false;
		}
	}
	count++;
}

void	gun_shots(t_cube *data, bool *shooting, int *sframe)
{
	data->frame = get_frame(data, "shoot/", (*sframe) + 8);
	if (!data->frame)
		return ;
	mlx_image_to_window(data->mlx_win, data->frame, 0, 0);
	(*sframe)++;
	if (*sframe == 15)
	{
		*shooting = false;
		*sframe = 0;
	}
}

void	animation(void *input)
{
	t_cube		*data;
	static bool	shooting;
	static int	sframe;

	data = (t_cube *)input;
	openthenooor(data);
	ft_mouse(data);
	if (mlx_is_mouse_down(data->mlx_win, 0) && sframe == 0)
		shooting = true;
	if (shooting)
		gun_shots(data, &shooting, &sframe);
	else if (!shooting)
		hold_gun(data);
}
