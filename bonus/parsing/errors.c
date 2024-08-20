/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:08:46 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/19 02:10:43 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	err_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	freemap(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
}

void	freedata(t_map_data *data)
{
	free(data->no_path);
	free(data->so_path);
	free(data->we_path);
	free(data->ea_path);
	free(data->f_color);
	free(data->c_color);
	freemap(data->cub_map);
	freemap(data->map);
}
