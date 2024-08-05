/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:17:04 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/04 16:23:43 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "MLX42/include/MLX42/MLX42.h"
# include "./parsing/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_pars_info {
	bool	north;
	bool	south;
	bool	east;
	bool	weast;
	bool	floor;
	bool	ceiling;
}	t_pars_info; 

typedef struct s_map_data {
	char		*f_color;
	char		*c_color;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	char		**cub_map;
	char		direction;
	int			h;
	int			w;
	int			x;
	int			y;
	int			farr[3];
	int			carr[3];
	mlx_texture_t	textures[4]; // no_textures is 0 | south is 1 | east is 2 | west is 3;
	t_pars_info	info;
}	t_map_data;

# endif