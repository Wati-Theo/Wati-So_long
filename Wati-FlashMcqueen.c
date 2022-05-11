/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-FlashMcqueen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:07:33 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/11 19:06:33 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	init_smap(t_map	*map)
{
	map->nb_boost = 0;
	map->current_boost = 0;
	map->nb_moves = 0;
	map->nb_player = 0;
	map->last_pos = 'f';
}

void	move(t_map *map, int start, int finish, int last_pos)
{
	if (map->map[finish] == '1')
		return ;
	if (map->map[finish] == 'C')
		map->current_boost++;
	if (map->map[finish] == 'E')
	{
		if (map->current_boost == map->nb_boost)
		{
			map->nb_moves++;
			ft_putnbr_fd(map->nb_moves, 2);
			write(2, "\n", 1);
			wati_exit(NULL, 1);
		}
		return ;
	}
	map->nb_moves++;
	map->last_pos = last_pos;
	map->map[start] = '0';
	map->map[finish] = 'P';
}

int	read_input(int keycode, t_map *map)
{
	int	pos;

	pos = ft_strchr(map->map, 'P') - map->map;
	if (keycode == 53)
		wati_exit(NULL, 1);
	if (keycode == 13)
		move(map, pos, pos - map->length, 'f');
	if (keycode == 0)
		move(map, pos, pos - 1, 'l');
	if (keycode == 1)
		move(map, pos, pos + map->length, 'b');
	if (keycode == 2)
		move(map, pos, pos + 1, 'r');
	disp_map(map);
	return (0);
}
