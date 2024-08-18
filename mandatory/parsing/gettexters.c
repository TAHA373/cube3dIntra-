/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettexters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:32 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/18 17:34:09 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_texter(t_map_data *data, char *file, char **path)
{
	(void)data;
	if (*path != NULL)
		return (free(file), 1);
	*path = ft_strdup(file);
	free(file);
	return (0);
}

int	gettexters2(t_map_data *data, char *file, char *dir)
{
	if (!ft_strcmp(dir, "WE"))
		return (handle_texter(data, file, &data->we_path));
	else if (!ft_strcmp(dir, "EA"))
		return (handle_texter(data, file, &data->ea_path));
	else if (!ft_strcmp(dir, "F"))
		return (handle_texter(data, file, &data->f_color));
	else if (!ft_strcmp(dir, "C"))
		return (handle_texter(data, file, &data->c_color));
	return (0);
}

int	gettexters(t_map_data *data, char *line, char *dir)
{
	int		i;
	char	*file;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i] || line[i] == '\n')
		return (1);
	file = ft_substr(line, i, ft_strlen(line));
	if (!file)
		return (1);
	if (!ft_strcmp(dir, "NO"))
		return (handle_texter(data, file, &data->no_path));
	else if (!ft_strcmp(dir, "SO"))
		return (handle_texter(data, file, &data->so_path));
	else if (gettexters2(data, file, dir))
		return (1);
	return (0);
}
