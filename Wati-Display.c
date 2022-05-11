/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:30:53 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/11 18:51:43 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	place_img(int x, int y, t_data *img, t_data *screen)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			dst = screen->addr + ((x + i) * (screen->bits_per_pixel / 8)
					+ (y + j) * screen->line_length);
			*(unsigned int *)dst = *(unsigned int *)(img->addr + i
					* (img->bits_per_pixel / 8) + j * img->line_length);
			i++;
		}
		j++;
	}
}

void	place_flashmcqueen(t_map *map, int i, int j)
{
	if (map->last_pos == 'l')
		place_img(i * 64, j * 64, &map->img[6], &map->screen);
	if (map->last_pos == 'r')
		place_img(i * 64, j * 64, &map->img[7], &map->screen);
	if (map->last_pos == 'f')
		place_img(i * 64, j * 64, &map->img[4], &map->screen);
	if (map->last_pos == 'b')
		place_img(i * 64, j * 64, &map->img[5], &map->screen);
}

void	which_sprite(t_map *map, char c, int i, int j)
{
	if (c == '1')
		place_img(i * 64, j * 64, &map->img[1], &map->screen);
	if (c == '0')
		place_img(i * 64, j * 64, &map->img[0], &map->screen);
	if (c == 'C')
		place_img(i * 64, j * 64, &map->img[2], &map->screen);
	if (c == 'E')
		place_img(i * 64, j * 64, &map->img[3], &map->screen);
	if (c == 'P')
		place_flashmcqueen(map, i, j);
}

void	disp_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->length)
		{
			which_sprite(map, map->map[i + j * map->length], i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->screen.img, 0, 0);
}
