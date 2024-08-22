/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:14:07 by tkannane          #+#    #+#             */
/*   Updated: 2024/08/22 01:02:22 by soel-bou         ###   ########.fr       */
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
		return (textures_delete(&cube), freemap(data.cub_map), (EXIT_FAILURE));
	if (initialize_image(&cube))
		return (freemap(data.cub_map), 1);
	mlx_loop_hook(cube.mlx_win, key_press, &cube);
	mlx_loop(cube.mlx_win);
	image_delete(&cube);
	mlx_terminate(cube.mlx_win);
	freemap(data.cub_map);
	return (EXIT_SUCCESS);
}
