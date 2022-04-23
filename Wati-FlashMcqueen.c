/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-FlashMcqueen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:07:33 by tschlege          #+#    #+#             */
/*   Updated: 2022/04/23 20:30:47 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	move(t_map *map, int start, int finish)
{
	if (map->map[finish] == '1')
		return ;
	if (map->map[finish] == 'C')
		map->current_boost++;
	if (map->map[finish] == 'E')
	{
		if (map->current_boost == map->nb_boost)
			wati_exit(NULL, 1);
		return ;
	}	
	map->map[start] = '0';
	map->map[finish] = 'P';
}

int	read_input(int keycode, t_map *map)
{
	int pos;

	pos = ft_strchr(map->map, 'P') - map->map;
	if (keycode == 53)
		wati_exit(NULL, 1);
	if (keycode == 13)
		move(map, pos, pos - map->length);
	if (keycode == 0)
		move(map, pos, pos - 1);
	if (keycode == 1)
		move(map, pos, pos + map->length);
	if (keycode == 2)
		move(map, pos, pos + 1);
	disp_map(map);
	return (0);
}
