/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:13:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/03 22:53:33 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	mlx_
*/

void	animation(void *input)
{
	static int count;
	t_cube			*data;
	mlx_texture_t	*txt;
	char src[10];

	data = (t_cube *)input;
	if (data->frame)
		mlx_delete_image(data->mlx_win, data->frame);
	ft_strlcat(src, ft_itoa(count));
	txt = 
}

int main()
{
	mlx_t *mlx = mlx_init(500, 600, "animation", false);
	mlx_texture_t *txt = mlx_load_png("images.png");
	mlx_image_t *img =  mlx_texture_to_image(mlx, txt);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}