/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:14:07 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/18 12:02:06 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_cube		cube;
	t_player	player;
	t_map_data	data;

	initialize_data(&data);
	ft_parsing(argc, argv, &data);
	initialize_cube(&cube, &data, &player);
	if (mlx_initialize(&cube))
		return (textures_delete (&cube), free(data.cub_map), (EXIT_FAILURE));
	initialize_image(&cube);
	mlx_set_cursor_mode(cube.mlx_win, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(cube.mlx_win, &cube.mouse_x, &cube.mouse_y);
	mlx_loop_hook(cube.mlx_win, key_press, &cube);
	mlx_loop(cube.mlx_win);
	mlx_terminate(cube.mlx_win);
	freemap(data.cub_map);
	image_delete(&cube);
	return (EXIT_SUCCESS);
}
