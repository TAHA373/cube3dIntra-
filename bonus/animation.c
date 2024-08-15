/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:13:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/15 18:07:31 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
	mlx_
*/

void	openthenooor(t_cube *data)
{
    int			player_x;
    int			player_y;
	static	int	x;
	static	int	y;
	
	player_x = (int)((data->player->x_position) / PIXEL_SIZE);
    player_y = (int)((data->player->y_position) / PIXEL_SIZE);
	if (data->map[player_y][player_x] == 'D')
	{
		x = player_x;
		y = player_y;
		data->map[player_y][player_x] = 'C';
	}
	else if (player_y != y || player_x !=  x)
	{
		data->map[y][x] = 'D';
	}
}

void animation(void *input)
{
	static int count;
	t_cube *data;
	mlx_texture_t *txt;
	char *num;
	char src[20];
	static int i;
	static bool max;
	static bool shooting;
	static int sframe;
	int x;
	int y;
	static int mouse;

	data = (t_cube *)input;
	// checkplayer(data);
	openthenooor(data);
	mlx_get_mouse_pos(data->mlx_win, &x, &y);
	if (mouse == 1)
	{
		mouse = 0;
		if (x < 800)
		{
			data->player->l_r_directions = -1;
			data->player->palyer_rotation_speed *= 2.5;
			update_player_place(data);
			mlx_set_mouse_pos(data->mlx_win, 800, 500);
			// mlx_set_mouse_pos(data->mlx_win, 800, y);
		}
		if (x > 800)
		{
			data->player->palyer_rotation_speed *= 2.5;
			data->player->l_r_directions = 1;
			update_player_place(data);
			mlx_set_mouse_pos(data->mlx_win, 800, 500);
			// mlx_set_mouse_pos(data->mlx_win, 800, y);
		}
		data->player->palyer_rotation_speed = 2 * (MATH_PI / 180);
		mlx_get_mouse_pos(data->mlx_win, &data->mouse_x, &data->mouse_y);
	}
	mouse++;

	if (mlx_is_mouse_down(data->mlx_win, 0) && sframe == 0)
		shooting = true;
	if (shooting)
	{

		if (data->frame)
			mlx_delete_image(data->mlx_win, data->frame);
		ft_strlcpy(src, "shoot/", sizeof(src));
		num = ft_itoa(sframe + 8);
		sframe++;
		ft_strlcat(src, num, sizeof(src));
		free(num);
		num = NULL;
		ft_strlcat(src, ".png", sizeof(src));
		txt = mlx_load_png(src);
		if (!txt)
			exit(1);
		data->frame = mlx_texture_to_image(data->mlx_win, txt);
		mlx_image_to_window(data->mlx_win, data->frame, 0, 0);
		mlx_delete_texture(txt);
		if (sframe == 17)
		{
			shooting = false;
			sframe = 0;
		}
	}
	else if (!shooting)
	{
		if (count == 2)
		{
			count = 0;
			if (data->frame)
				mlx_delete_image(data->mlx_win, data->frame);
			ft_strlcpy(src, "hold/", sizeof(src));
			num = ft_itoa(i + 1);
			ft_strlcat(src, num, sizeof(src));
			free(num);
			num = NULL;
			ft_strlcat(src, ".png", sizeof(src));
			txt = mlx_load_png(src);
			if (!txt)
				exit(1);
			data->frame = mlx_texture_to_image(data->mlx_win, txt);
			mlx_image_to_window(data->mlx_win, data->frame, 0, 0);
			mlx_delete_texture(txt);
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
}

// int main()
// {
// 	t_cube data;
// 	data.mlx_win = mlx_init(1800, 1200, "animation", false);
// 	mlx_loop_hook(data.mlx_win, animation, &data);
// 	mlx_loop(data.mlx_win);
// }