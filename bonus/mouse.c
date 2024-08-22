/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:59:50 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/20 21:12:53 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	left_mouse(t_cube *data)
{
	data->player->l_r_directions = -1;
	data->player->player_rotation_speed *= 2.5;
	update_player_place(data);
	mlx_set_mouse_pos(data->mlx_win, 540, 900);
}

void	right_mouse(t_cube *data)
{
	data->player->l_r_directions = 1;
	data->player->player_rotation_speed *= 2.5;
	update_player_place(data);
	mlx_set_mouse_pos(data->mlx_win, 540, 900);
}

void	ft_mouse(t_cube *data)
{
	int			x;
	int			y;
	static int	mouse;

	if (data->mouse_state == ON)
	{
		mlx_get_mouse_pos(data->mlx_win, &x, &y);
		if (mouse == 1)
		{
			mouse = 0;
			if (x < 540)
				left_mouse(data);
			if (x > 540)
				right_mouse(data);
			data->player->player_rotation_speed = 2 * (MATH_PI / 180);
			mlx_get_mouse_pos(data->mlx_win, &data->mouse_x, &data->mouse_y);
		}
		mouse++;
	}
}
