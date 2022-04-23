/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:30:53 by tschlege          #+#    #+#             */
/*   Updated: 2022/04/23 19:04:21 by tschlege         ###   ########lyon.fr   */
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
			dst = screen->addr + ((x + i) * (screen->bits_per_pixel / 8) + (y + j) * screen->line_length);
			*(unsigned int *)dst = *(unsigned int *)(img->addr + i * (img->bits_per_pixel / 8) + j * img->line_length);
			i++;
		}
		j++;
	}
}

void	load_img(t_map *map)
{
	int		img_width;
	int		img_height;

	map->img[0].img = mlx_xpm_file_to_image(map->mlx, "assets/0.xpm",
			&img_width, &img_height);
	map->img[0].addr = mlx_get_data_addr(map->img[0].img, &map->img[0].bits_per_pixel,
			&map->img[0].line_length, &map->img[0].endian);
				
	map->img[1].img = mlx_xpm_file_to_image(map->mlx, "assets/1.xpm",
			&img_width, &img_height);
	map->img[1].addr = mlx_get_data_addr(map->img[1].img, &map->img[1].bits_per_pixel,
			&map->img[1].line_length, &map->img[1].endian);
			
	map->img[2].img = mlx_xpm_file_to_image(map->mlx, "assets/C.xpm",
			&img_width, &img_height);
	map->img[2].addr = mlx_get_data_addr(map->img[2].img, &map->img[2].bits_per_pixel,
			&map->img[2].line_length, &map->img[2].endian);
			
	map->img[3].img = mlx_xpm_file_to_image(map->mlx, "assets/E.xpm",
			&img_width, &img_height);
	map->img[3].addr = mlx_get_data_addr(map->img[3].img, &map->img[3].bits_per_pixel,
			&map->img[3].line_length, &map->img[3].endian);
	
	map->img[4].img = mlx_xpm_file_to_image(map->mlx, "assets/P_up.xpm",
			&img_width, &img_height);
		map->img[4].addr = mlx_get_data_addr(map->img[4].img, &map->img[4].bits_per_pixel,
			&map->img[4].line_length, &map->img[4].endian);
			
	map->img[5].img = mlx_xpm_file_to_image(map->mlx, "assets/P_down.xpm",
			&img_width, &img_height);
		map->img[5].addr = mlx_get_data_addr(map->img[5].img, &map->img[5].bits_per_pixel,
			&map->img[5].line_length, &map->img[5].endian);

	map->img[6].img = mlx_xpm_file_to_image(map->mlx, "assets/P_left.xpm",
			&img_width, &img_height);
		map->img[6].addr = mlx_get_data_addr(map->img[6].img, &map->img[6].bits_per_pixel,
			&map->img[6].line_length, &map->img[6].endian);	

	map->img[7].img = mlx_xpm_file_to_image(map->mlx, "assets/P_right.xpm",
			&img_width, &img_height);
		map->img[7].addr = mlx_get_data_addr(map->img[7].img, &map->img[7].bits_per_pixel,
			&map->img[7].line_length, &map->img[7].endian);
}

void	place_FlashMcqueen(t_map *map, int i, int j)
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
		place_FlashMcqueen(map, i, j);
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
	//place_img(0, 0, &map->img[0], &map->screen);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->screen.img, 0, 0);
}
