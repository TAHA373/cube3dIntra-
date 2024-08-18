/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettexters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:38:32 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/17 16:54:43 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	gettexters2(t_map_data *data, char *file, char *dir)
{
	if (!ft_strcmp(dir, "WE"))
	{
		if (data->we_path != NULL) //deja kayn!!
			return (1);
		data->we_path = ft_strdup(file);
		free(file);	
	}
	else if (!ft_strcmp(dir, "EA"))
	{
		if (data->ea_path != NULL) //deja kayn!!
			return (1);
		data->ea_path = ft_strdup(file);
		free(file);	 
	}
	else if (!ft_strcmp(dir, "F"))
	{
		if (data->f_color != NULL) //deja kayn!!
			return (1);
		data->f_color = ft_strdup(file);
		free(file);	
	}
	else if (!ft_strcmp(dir, "C"))
	{
		if (data->c_color != NULL) //deja kayn!!
			return (1);
		data->c_color = ft_strdup(file);
		free(file);
	}
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
	{
		if(data->no_path != NULL)
			return (free(file), file = NULL, 1);
		data->no_path = ft_strdup(file);
		free(file);
	}
	else if (!ft_strcmp(dir, "SO"))
	{
		if(data->so_path != NULL)
			return (free(file), file = NULL, 1);
		data->so_path = ft_strdup(file);
		free(file);	
	}
	else if (gettexters2(data, file, dir))
		return (free(file), file = NULL, 1);
	
	return (0);
}