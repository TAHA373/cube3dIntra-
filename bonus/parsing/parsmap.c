/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 01:18:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/19 02:38:38 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	parsspaces(t_map_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->cub_map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (parsborders(data, i, j, '0') || parsborders(data, i, j, 'N')
				|| parsborders(data, i, j, 'E') || parsborders(data, i, j, 'S')
				|| parsborders(data, i, j, 'W'))
				return (1);
			if (map[i][j] == 'D' && !parsdoor(data, i, j))
				return (1);
		}
	}
	return (0);
}

int	checkborders(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1')
		return (1);
	i = ft_strlen(line) - 1;
	while (i && (line[i] == ' ' || line[i] == '\t'))
		i--;
	if (line[i] != '1')
		return (1);
	return (0);
}

int	checkones(t_map_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->cub_map[0][++i])
	{
		if (data->cub_map[0][i] != '1' && data->cub_map[0][i] != ' '
			&& data->cub_map[0][i] != '\t')
			return (1);
	}
	i = -1;
	while (data->cub_map[++i])
	{
		if (checkborders(data->cub_map[i]))
			return (1);
	}
	j = -1;
	while (data->cub_map[i - 1][++j])
	{
		if (data->cub_map[i - 1][j] != '1' && data->cub_map[i - 1][j] != ' '
			&& data->cub_map[i - 1][j] != '\t')
			return (1);
	}
	return (0);
}

void	getdemonsion(t_map_data *data)
{
	int	i;
	int	j;

	(1) && (data->h = 0, data->w = 0, j = -1, i = -1);
	while (data->cub_map[++i])
	{
		if (data->w < (int)ft_strlen(data->cub_map[i]))
			data->w = (int)ft_strlen(data->cub_map[i]);
	}
	data->h = i;
	i = -1;
	while (data->cub_map[++i])
	{
		j = -1;
		while (data->cub_map[i][++j])
		{
			if (data->cub_map[i][j] == 'N' || data->cub_map[i][j] == 'E'
				|| data->cub_map[i][j] == 'W' || data->cub_map[i][j] == 'S')
			{
				data->direction = data->cub_map[i][j];
				data->x = j;
				data->y = i;
			}
		}
	}
}

int	parsmap(t_map_data *data)
{
	char	**map;
	char	*linemap;

	map = findthemap(data->map);
	if (!map)
		return (1);
	linemap = getlinemap(map);
	freemap(data->map);
	if (!linemap)
		return (1);
	if (parslinemap(linemap))
		return (free(linemap), 1);
	data->cub_map = ft_split(linemap, '\n');
	free(linemap);
	if (!data->cub_map)
		return (1);
	getdemonsion(data);
	if (checkones(data))
		return (1);
	if (parsspaces(data))
		return (1);
	return (0);
}
