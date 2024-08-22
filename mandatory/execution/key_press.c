/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:39:59 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/20 22:09:31 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_release(t_cube *cube)
{
	cube->player->b_f_directions = 0;
	cube->player->l_r_directions = 0;
}

void	key_press2(t_cube *cube)
{
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_LEFT))
	{
		cube->player->l_r_directions = -1;
		update_player_place(cube);
	}
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_RIGHT))
	{
		cube->player->l_r_directions = 1;
		update_player_place(cube);
	}
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_A))
		update_player_place_left(cube);
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_D))
		update_player_place_right(cube);
}

void	key_press(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx_win);
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_UP)
		|| mlx_is_key_down(cube->mlx_win, MLX_KEY_W))
	{
		cube->player->b_f_directions = 1;
		update_player_place(cube);
	}
	if (mlx_is_key_down(cube->mlx_win, MLX_KEY_DOWN)
		|| mlx_is_key_down(cube->mlx_win, MLX_KEY_S))
	{
		cube->player->b_f_directions = -1;
		update_player_place(cube);
	}
	key_press2(cube);
	clear_image(cube->image);
	cast_rays(cube);
}
