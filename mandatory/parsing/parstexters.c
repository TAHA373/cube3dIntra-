/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstexters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:15:01 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/17 16:16:44 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int checkfile(char *file, mlx_texture_t **txt)
{
	int		i;
	char	*tfile;
	int		len;

	i = 0;
	len = ft_strlen(file);
	while (len > 0 && (file[len - 1] == ' ' || file[len - 1] == '\t' || file[len - 1] == '\n'))
		len--;
	tfile = ft_substr(file, 0, len);
	*txt = mlx_load_png(tfile);
	free(tfile);
	tfile = NULL;
	if (!txt)
		return (1);
	return (0);
}


int	parsdirections(t_map_data *data)
{
	if (!data->ea_path || !data->no_path || !data->so_path || !data->we_path)
		return (ft_putstr_fd("Error\nMessing Texters\n", 2), 1);
	if (checkfile(data->ea_path, &data->east) || checkfile(data->no_path, &data->north)
		|| checkfile(data->so_path, &data->south) || checkfile(data->we_path, &data->west))
		return (ft_putstr_fd("Error\nInvalid Texters files\n", 2),1);
	return (0);
}