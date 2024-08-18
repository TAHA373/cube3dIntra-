/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:01:42 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/18 17:05:22 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	checkafternewline(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}

int	parslinemap(char *map)
{
	int	i;
	int	pos;

	(1) && (i = -1, pos = 0);
	while (map[++i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != '\n'
			&& map[i] != ' ' && map[i] != 'N' && map[i] != 'E'
			&& map[i] != 'S' && map[i] != 'W')
			return (1);
		if (map[i] == '\n' && checkafternewline(&map[i + 1]))
			return (1);
		if (map[i] == 'N' || map[i] == 'E' || map[i] == 'S' || map[i] == 'W')
			pos++;
	}
	if (pos != 1)
		return (1);
	return (0);
}

char	*getlinemap(char **map)
{
	char	*linemap;
	char	*tmp;
	int		i;

	i = -1;
	linemap = ft_strdup("");
	while (map[++i])
	{
		tmp = ft_strdup(linemap);
		free(linemap);
		linemap = ft_strjoin(tmp, map[i]);
		if (!linemap)
			return (free(tmp), tmp = NULL, NULL);
		free(tmp);
	}
	return (linemap);
}

char	**findthemap(char **data)
{
	int	i;
	int	j;

	i = -1;
	while (data[++i])
	{
		j = 0;
		while (data[i][j] == ' ' || data[i][j] == '\t' || data[i][j] == '\n')
			j++;
		if (data[i][j] == '1')
			return (&data[i]);
	}
	return (NULL);
}

int	parsborders(t_map_data *data, int i, int j, char c)
{
	char	**map;

	map = data->cub_map;
	if (j < data->w)
	{
		if (map[i][j] == c && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
			return (1);
	}
	if (j > 0)
	{
		if (map[i][j] == c && (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'))
			return (1);
	}
	if (i < data->h)
	{
		if (map[i][j] == c && (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'))
			return (1);
	}
	if (i > 0)
	{
		if (map[i][j] == c && (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'))
			return (1);
	}
	return (0);
}
