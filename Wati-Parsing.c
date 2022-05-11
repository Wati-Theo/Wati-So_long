/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:18:41 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/11 19:06:33 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	line_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->length)
	{
		if (map->map[i] != '1')
			wati_exit("Invalid_map_line", 0);
		i++;
	}
	i = map->length * (map->height -1);
	while (map->map[i])
	{
		if (map->map[i] != '1')
			wati_exit("Invalid_map_line", 0);
		i++;
	}
}

void	col_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[(map->length * i)] != '1')
			wati_exit("Invalid_map_col", 0);
		i++;
	}
	i = 1;
	while (i <= map->height)
	{
		if (map->map[(map->length * i) - 1] != '1')
			wati_exit("Invalid_map_col", 0);
		i++;
	}
}

void	check_map(t_map	*map)
{
	int	i;

	i = 0;
	while (i < map->length * map->height)
	{
		if (map->map[i] != 'C' && map->map[i] != 'E' && map->map[i] != 'P'
			&& map->map[i] != '1' && map->map[i] != '0')
			wati_exit("Invalid_map_CEP", 0);
		if (map->map[i] == 'C')
			map->nb_boost++;
		if (map->map[i] == 'P')
			map->nb_player++;
		i++;
	}
	i = 0;
	if (map->nb_player > 1)
		while (++i < map->nb_player)
			map->map[ft_strrchr(map->map, 'P') - map->map] = '0';
	if (!ft_strchr(map->map, 'C') || !ft_strchr(map->map, 'E')
		|| !ft_strchr(map->map, 'P'))
		wati_exit("Invalid_map_CEP", 0);
	line_check(map);
	col_check(map);
}

void	create_map(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		wati_exit("fd_err", 0);
	map->map = ft_calloc((map->length * map->height + 1), sizeof(char));
	line = get_next_line(fd);
	if (!line)
		wati_exit("Invalid_map_empty", 0);
	while (line)
	{
		ft_strlcat(map->map, line, -1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_map(map);
}

void	wati_parser(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		wati_exit("fd_err", 0);
	line = get_next_line(fd);
	if (!line)
		wati_exit("Invalid_map_empty", 0);
	map->length = ft_strlen(line);
	map->height = 0;
	while (line)
	{
		if ((int)ft_strlen(line) != map->length)
		{
			free(line);
			wati_exit("Invalid_map_len", 0);
		}
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
	create_map(path, map);
}
