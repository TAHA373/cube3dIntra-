/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:24:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/22 01:25:19 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_i(char *file)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
	return (i);
}

int	set_data(t_map_data *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = get_i(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	data->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->map)
		return (close(fd), 1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i++] = ft_strdup(line);
		if (!data->map[i - 1])
			return (free(line), freemap(data->map), 1);
		free(line);
	}
	return (data->map[i] = NULL, 0);
}

int	parsargs(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (ft_putstr_fd("Error\nINVALID ARGS!\n", 2), 1);
	if (ft_strlen(argv[1]) <= 4)
		return (ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2), 1);
	while (argv[1][i])
		i++;
	if (ft_strncmp(&argv[1][i - 4], ".cub ", 4))
	{
		ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2);
		return (1);
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
		return (ft_putstr_fd("Error\nCan't open the mapfile\n", 2), 1);
	close(i);
	return (0);
}

void	ft_parsing(int argc, char **argv, t_map_data *data)
{
	if (parsargs(argc, argv) || set_data(data, argv[1]))
		exit(1);
	if (parsinfos(data) || parsdirections(data) || parscolors(data))
	{
		freedata(data);
		exit(1);
	}
	free(data->no_path);
	free(data->so_path);
	free(data->we_path);
	free(data->ea_path);
	if (parsmap(data))
	{
		ft_putstr_fd("Error\nError in the Map\n", 2);
		freemap(data->cub_map);
		exit(1);
	}
}
