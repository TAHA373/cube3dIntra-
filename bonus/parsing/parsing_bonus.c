/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:16:28 by soel-bou          #+#    #+#             */
/*   Updated: 2024/08/19 02:18:02 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

// int	set_data(t_map_data *data, char *file)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	while (get_next_line(fd))
// 		i++;
// 	close(fd);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	data->map = (char **)malloc(sizeof(char *) * (i + 1));
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		data->map[i++] = ft_strdup(line);
// 		free(line);
// 	}
// 	return (data->map[i] = NULL, 0);
// }

// int	gettexters2(t_map_data *data, char *file, char *dir)
// {
// 	if (!ft_strcmp(dir, "WE"))
// 	{
// 		if (data->we_path != NULL) //deja kayn!!
// 			return (1);
// 		data->we_path = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "EA"))
// 	{
// 		if (data->ea_path != NULL) //deja kayn!!
// 			return (1);
// 		data->ea_path = ft_strdup(file);	 
// 	}
// 	else if (!ft_strcmp(dir, "F"))
// 	{
// 		if (data->f_color != NULL) //deja kayn!!
// 			return (1);
// 		data->f_color = ft_strdup(file);	
// 	}
// 	else if (!ft_strcmp(dir, "C"))
// 	{
// 		if (data->c_color != NULL) //deja kayn!!
// 			return (1);
// 		data->c_color = ft_strdup(file);	
// 	}
// 	return (0);
// }

// int	gettexters(t_map_data *data, char *line, char *dir)
// {
// 	int		i;
// 	char	*file;

// 	i = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (!line[i] || line[i] == '\n')
// 		return (1);
// 	file = ft_substr(line, i, ft_strlen(line));
// 	if (!file)
// 		return (1);
// 	if (!ft_strcmp(dir, "NO"))
// 	{
// 		if(data->no_path != NULL)
// 			return (1);
// 		data->no_path = ft_strdup(file);
// 	}
// 	else if (!ft_strcmp(dir, "SO"))
// 	{
// 		if(data->so_path != NULL)
// 			return (1);
// 		data->so_path = ft_strdup(file);	
// 	}
// 	else if (gettexters2(data, file, dir))
// 		return (1);
// 	return (0);
// }


// int	parscf(t_map_data *data, int i, int j)
// {
// 	if(data->map[i][j] == 'F')
// 	{
// 		if(gettexters(data, &data->map[i][j + 1], "F"))
// 			return (printf("her1e\n"),1);
// 	}
// 	else if(data->map[i][j] == 'C')
// 	{
// 		if(gettexters(data, &data->map[i][j + 1], "C"))
// 			return (printf("here2\n"),1);
// 	}
// 	else if(data->map[i][j] != '1' && data->map[i][j] != ' '
// 		&& data->map[i][j] != '\t' && data->map[i][j] != '\n'
// 		&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
// 		&& data->map[i][j] != 'E' && data->map[i][j] != 'W')
// 		return (printf("(%c) (%s)\n", data->map[i][j], data->map[i]),1);
// 	return (0);
// }

// int parsnswe(t_map_data *data, int i, int j)
// {
// 	if(data->map[i][j] == 'N')
// 	{
// 		if(data->map[i][j + 1] != 'O' || gettexters(data, &data->map[i][j + 2], "NO"))
// 			return (printf("here4\n"),1);
// 	}
// 	else if(data->map[i][j] == 'S')
// 	{
// 		if(data->map[i][j + 1] != 'O' || gettexters(data, &data->map[i][j + 2], "SO"))
// 			return (printf("here5\n"),1);
// 	}
// 	else if(data->map[i][j] == 'W')
// 	{
// 		if(data->map[i][j + 1] != 'E' || gettexters(data, &data->map[i][j + 2], "WE"))
// 			return (printf("here6\n"),1);
// 	}
// 	else if(data->map[i][j] == 'E')
// 	{
// 		if(data->map[i][j + 1] != 'A' || gettexters(data, &data->map[i][j + 2], "EA"))
// 			return (printf("here7\n"),1);
// 	}
// 	return (0);
// }

// int parsinfos(t_map_data *data)
// {
// 	char **map = data->map;
// 	int i;
// 	int j;

// 	i = -1;
// 	while(map[++i])
// 	{
// 		j = 0;
// 		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n'))
// 			j++;
// 		if (map[i][j] && (parsnswe(data, i, j) || parscf(data, i, j)))
// 			return (printf("here\n"), 1);
// 	}
// 	return (0);
// }

// int	parsargs(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	if (argc != 2)
// 		return (1);
// 	if (ft_strlen(argv[1]) <= 4)
// 		return (ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2), 1);
// 	while (argv[1][i])
// 		i++;
// 	if (ft_strncmp(&argv[1][i - 4], ".cub ", 4))
// 	{
// 		ft_putstr_fd("Error\nINVALID FILE NAME!\n", 2);
// 		return (1);
// 	}
// 	i = open(argv[1], O_RDONLY);
// 	if (i < 0)
// 		return (ft_putstr_fd("Error\nCan't open the mapfile\n", 2), 1);
// 	return (0);
// }

// int checkfile(char *file, mlx_texture_t **txt)
// {
// 	int		i;
// 	char	*tfile;
// 	int		len;

// 	i = 0;
// 	len = ft_strlen(file);
// 	while (len > 0 && (file[len - 1] == ' ' || file[len - 1] == '\t' || file[len - 1] == '\n'))
// 		len--;
// 	tfile = ft_substr(file, 0, len);
// 	*txt = mlx_load_png(tfile);
// 	free(tfile);
// 	tfile = NULL;
// 	if (!txt)
// 		return (1);
// 	return (0);
// }


// int	parsdirections(t_map_data *data)
// {
// 	if (!data->ea_path || !data->no_path || !data->so_path || !data->we_path)
// 		return (ft_putstr_fd("Error\nMessing Texters\n", 2), 1);
// 	if (checkfile(data->ea_path, &data->east) || checkfile(data->no_path, &data->north)
// 		|| checkfile(data->so_path, &data->south) || checkfile(data->we_path, &data->west))
// 		return (ft_putstr_fd("Error\nInvalid Texters files\n", 2),1);
// 	return (0);
// }

// int commacounter(char *line)
// {
// 	int i;
// 	int c;

// 	i = -1;
// 	c = 0;
// 	if (!line)
// 		return (1);
// 	while (line[++i])
// 	{
// 		if (line[i] == ',')
// 			c++;
// 	}
// 	if (c != 2)
// 		return (1);
// 	return (0);
// }

// int checknumbers(char **nums, int *colors)
// {
// 	if (!nums[0] || !nums[1] || !nums[2])
// 		return (1);
// 	colors[0] = ft_atoi(nums[0]);
// 	colors[1] = ft_atoi(nums[1]);
// 	colors[2] = ft_atoi(nums[2]);
// 	if ((colors[0] >= 0 && colors[0] <= 255)
// 		&& (colors[1] >= 0 && colors[1] <= 255)
// 		&& (colors[2] >= 0 && colors[2] <= 255))
// 		return (0);
// 	return (1);
// }

// int checkforc(char *line)
// {
// 	int i;

// 	i = -1;
// 	while(line[++i])
// 	{
// 		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != '\n' && line[i] != ' ')
// 			return (1);
// 	}
// 	return (0);
// }

// int parscolors(t_map_data *data)
// {
// 	char **ccors;
// 	char **fcors;
// 	int i;

// 	i = -1;
// 	if (!data->f_color || !data->c_color)
// 		return (1);
// 	if (commacounter(data->c_color) || commacounter(data->f_color))
// 		return (printf("here\n"), 1);
// 	if (checkforc(data->c_color) || checkforc(data->f_color))
// 		return (printf("hi\n"), 1);
// 	ccors = ft_split(data->c_color, ',');
// 	fcors = ft_split(data->f_color, ',');
// 	if (checknumbers(fcors, data->farr) || checknumbers(ccors, data->carr))
// 		return (printf("here\n"),1);
// 	return (0);
// }

// int	checkafternewline(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (line[i] == '\n')
// 		return (1);
// 	return (0);
// }

// int	parslinemap(char *map)
// {
// 	int i;
// 	int	pos;
	
// 	(1) && (i = -1, pos = 0);
// 	while (map[++i])
// 	{
// 		if (map[i] != '1' && map[i] != '0' && map[i] != '\n'
// 			&& map[i] != ' ' && map[i] != 'N' && map[i] != 'E'
// 			&& map[i] != 'S' && map[i] != 'W' && map[i] != 'D')
// 			return (1);
// 		if (map[i] == '\n' && checkafternewline(&map[i + 1]))
// 			return (printf("here\n"),1);
// 		if (map[i] == 'N' || map[i] == 'E' || map[i] == 'S' || map[i] == 'W')
// 			pos++;
// 	}
// 	if (pos != 1)
// 		return (1);
// 	return (0);
// }

// char	*getlinemap(char **map)
// {
// 	char	*linemap;
// 	char	*tmp;
// 	int		i;
	
// 	i = -1;
// 	linemap = ft_strdup("");
// 	while (map[++i])
// 	{
// 		tmp = ft_strdup(linemap);
// 		linemap = ft_strjoin(tmp, map[i]);
// 		free(tmp);
// 	}
// 	return (linemap);
// }

// char **findthemap(char **data)
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	while(data[++i])
// 	{
// 		j = 0;
// 		while (data[i][j] == ' ' || data[i][j] == '\t' || data[i][j] == '\n')
// 			j++;
// 		if (data[i][j] == '1')
// 			return (&data[i]);
// 	}
// 	return (NULL);
// }

// int parsborders(t_map_data *data, int i, int j, char c)
// {
// 	char **map;

// 	map  = data->cub_map;
// 	if (j < data->w)
// 	{
// 		if (map[i][j] == c && (map[i][j + 1] == ' ' ||  map[i][j + 1] == '\t'))
// 			return (1);
// 	}
// 	if (j > 0)
// 	{
// 		if (map[i][j] == c && (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'))
// 			return (1);
// 	}
// 	if (i < data->h)
// 	{
// 		if (map[i][j] == c && (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'))
// 			return ( 1);
// 	}
// 	if (i > 0)
// 	{
// 		if (map[i][j] == c && (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'))
// 			return (1);
// 	}
// 	return (0);
// }

// int parsdoor(t_map_data *data, int i, int j)
// {
// 	char **map;

// 	map = data->cub_map;
// 	//TODO add player chars(NSWE) 2
// 	if (map[i][j] == 'D' && (map[i][j + 1] == '1' && map[i][j - 1] == '1'))
// 		return (1);
// 	if (map[i][j] == 'D' && (map[i + 1 ][j] == '1' && map[i - 1][j] == '1'))
// 		return (1);
// 	return (0);
// }

// int parsspaces(t_map_data *data)
// {
// 	char **map;
// 	int i;
// 	int j;

// 	map = data->cub_map;
// 	i = -1;
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if (parsborders(data, i, j, '0') || parsborders(data, i, j, 'N')
// 				|| parsborders(data, i, j,'E') || parsborders(data, i, j, 'S')
// 				|| parsborders(data,i, j, 'W'))
// 				return (1);
// 			if (map[i][j] == 'D' && !parsdoor(data, i, j))
// 				return (1);
// 		}
// 	}
// 	return (0);
// }

// int checkborders(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (line[i] != '1')
// 		return (1);
// 	i = ft_strlen(line) - 1;
// 	while (i && (line[i] == ' ' || line[i] == '\t'))
// 		i--;
// 	if (line[i] != '1')
// 		return (1);
// 	return (0);
// }

// int checkones(t_map_data *data)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (data->cub_map[0][++i])
// 	{
// 		if (data->cub_map[0][i] != '1' && data->cub_map[0][i] != ' '
// 			&& data->cub_map[0][i] != '\t')
// 			return (1);
// 	}
// 	i = -1;
// 	while (data->cub_map[++i])
// 	{
// 		if (checkborders(data->cub_map[i]))
// 			return (1);
// 	}
// 	j = -1;
// 	while (data->cub_map[i - 1][++j])
// 	{
// 		if (data->cub_map[i - 1][j] != '1' && data->cub_map[i - 1][j] != ' '
// 			&& data->cub_map[i - 1][j] != '\t')
// 			return (1);
// 	}
// 	return (0);
// }
// void	printmap(char **map)
// {
// 	int i;

// 	i = 0;
// 	while (map[i])
// 		printf("%s\n", map[i++]);
// }

// void	getdemonsion(t_map_data *data)
// {
// 	int	i;
// 	int	j;

// 	(1) && (data->h = 0, data->w = 0, j = -1, i = -1);
// 	while (data->cub_map[++i])
// 	{
// 		if (data->w < (int)ft_strlen(data->cub_map[i]))
// 			data->w = (int)ft_strlen(data->cub_map[i]);
// 	}
// 	data->h = i;
// 	i = -1;
// 	while (data->cub_map[++i])
// 	{
// 		j = -1;
// 		while (data->cub_map[i][++j])
// 		{
// 			if (data->cub_map[i][j] == 'N' || data->cub_map[i][j] == 'E'
// 				|| data->cub_map[i][j] == 'W' || data->cub_map[i][j] == 'S')
// 			{
// 				data->direction = data->cub_map[i][j];
// 				data->x = j;
// 				data->y = i;	
// 			}
// 		}
// 	}
// }

// int parsmap(t_map_data *data)
// {
// 	char	**map;
// 	char	*linemap;
	
// 	map = findthemap(data->map);
// 	if (!map)
// 		return (1);
// 	linemap = getlinemap(map);
// 	if (!linemap)
// 		return (1);
// 	if (parslinemap(linemap)) //bug in /n after /n
// 		return (1);
// 	data->cub_map = ft_split(linemap, '\n');
// 	getdemonsion(data);
// 	if (checkones(data))
// 		return (1);
// 	if (parsspaces(data))
// 		return (1);
// 	return (0);
// }

// void	ft_parsing(int argc, char **argv, t_map_data *data)
// {
// 	if (parsargs(argc, argv))
// 		exit(1);
// 	if(set_data(data, argv[1]))
// 		exit(1);
// 	if(parsinfos(data))
// 		exit(1);
// 	if (parsdirections(data))
// 		exit (1);
// 	if (parscolors(data))
// 	{
// 		printf("err\n");
// 		exit(1);
// 	}
// 	if (parsmap(data))
// 	{
// 		printf("err in map");
// 		exit(1);
// 	}
// }

int	parsdoor(t_map_data *data, int i, int j)
{
	char	**map;

	map = data->cub_map;
	//TODO add player chars(NSWE) 2
	if (map[i][j] == 'D' && (map[i][j + 1] == '1' && map[i][j - 1] == '1'))
		return (1);
	if (map[i][j] == 'D' && (map[i + 1 ][j] == '1' && map[i - 1][j] == '1'))
		return (1);
	return (0);
}

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
		return (1);
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