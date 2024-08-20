/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinfos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:17:17 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/19 02:10:52 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	parscf(t_map_data *data, int i, int j)
{
	if (data->map[i][j] == 'F')
	{
		if (gettexters(data, &data->map[i][j + 1], "F"))
			return (1);
	}
	else if (data->map[i][j] == 'C')
	{
		if (gettexters(data, &data->map[i][j + 1], "C"))
			return (1);
	}
	else if (data->map[i][j] != '1' && data->map[i][j] != ' '
		&& data->map[i][j] != '\t' && data->map[i][j] != '\n'
		&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
		&& data->map[i][j] != 'E' && data->map[i][j] != 'W')
		return (1);
	return (0);
}

int	parsnswe(t_map_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		if (data->map[i][j + 1] != 'O'
			|| gettexters(data, &data->map[i][j + 2], "NO"))
			return (1);
	}
	else if (data->map[i][j] == 'S')
	{
		if (data->map[i][j + 1] != 'O'
			|| gettexters(data, &data->map[i][j + 2], "SO"))
			return (1);
	}
	else if (data->map[i][j] == 'W')
	{
		if (data->map[i][j + 1] != 'E'
			|| gettexters(data, &data->map[i][j + 2], "WE"))
			return (1);
	}
	else if (data->map[i][j] == 'E')
	{
		if (data->map[i][j + 1] != 'A'
			|| gettexters(data, &data->map[i][j + 2], "EA"))
			return (1);
	}
	return (0);
}

int	parsinfos(t_map_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = data->map;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' '
			|| map[i][j] == '\t' || map[i][j] == '\n'))
			j++;
		if (map[i][j] && (parsnswe(data, i, j) || parscf(data, i, j)))
			return (ft_putstr_fd("Error\nErro in texters data\n", 2), 1);
	}
	return (0);
}
