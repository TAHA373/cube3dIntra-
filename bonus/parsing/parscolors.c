/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parscolors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 01:43:30 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/22 01:08:18 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	commacounter(char *line)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	if (!line)
		return (1);
	while (line[++i])
	{
		if (line[i] == ',')
			c++;
	}
	if (c != 2)
		return (1);
	return (0);
}

int	checknumbers(char **nums, int *colors)
{
	if (!nums[0] || !nums[1] || !nums[2])
		return (1);
	colors[0] = ft_atoi(nums[0]);
	colors[1] = ft_atoi(nums[1]);
	colors[2] = ft_atoi(nums[2]);
	freemap(nums);
	if ((colors[0] >= 0 && colors[0] <= 255)
		&& (colors[1] >= 0 && colors[1] <= 255)
		&& (colors[2] >= 0 && colors[2] <= 255))
		return (0);
	return (1);
}

int	checkforc(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ','
			&& line[i] != '\n' && line[i] != ' ')
			return (1);
	}
	return (0);
}

void	rmnewline(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
	}
}

int	parscolors(t_map_data *data)
{
	char	**ccors;
	char	**fcors;
	int		i;

	i = -1;
	ccors = NULL;
	fcors = NULL;
	if (!data->f_color || !data->c_color)
		return (ft_putstr_fd("Error\n Missing color\n", 2), 1);
	if (commacounter(data->c_color) || commacounter(data->f_color))
		return (ft_putstr_fd("Error\n in color\n", 2), 1);
	if (checkforc(data->c_color) || checkforc(data->f_color))
		return (ft_putstr_fd("Error\n char in color\n", 2), 1);
	rmnewline(data->f_color);
	rmnewline(data->c_color);
	ccors = ft_split(data->c_color, ',');
	fcors = ft_split(data->f_color, ',');
	free(data->c_color);
	data->c_color = NULL;
	free(data->f_color);
	data->f_color = NULL;
	if (checknumbers(fcors, data->farr) || checknumbers(ccors, data->carr))
		return (checknumbers(ccors, data->carr),
			ft_putstr_fd("Error\n in numbers\n", 2), 1);
	return (0);
}
