/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Load_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:30:09 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/11 18:56:34 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	load_img_3(t_map *map)
{
	int		img_width;
	int		img_height;

	map->img[6].img = mlx_xpm_file_to_image(map->mlx, "assets/P_left.xpm",
			&img_width, &img_height);
	map->img[6].addr = mlx_get_data_addr(map->img[6].img,
			&map->img[6].bits_per_pixel, &map->img[6].line_length,
			&map->img[6].endian);
	map->img[7].img = mlx_xpm_file_to_image(map->mlx, "assets/P_right.xpm",
			&img_width, &img_height);
	map->img[7].addr = mlx_get_data_addr(map->img[7].img,
			&map->img[7].bits_per_pixel, &map->img[7].line_length,
			&map->img[7].endian);
}

void	load_img_2(t_map *map)
{
	int		img_width;
	int		img_height;

	map->img[3].img = mlx_xpm_file_to_image(map->mlx, "assets/E.xpm",
			&img_width, &img_height);
	map->img[3].addr = mlx_get_data_addr(map->img[3].img,
			&map->img[3].bits_per_pixel, &map->img[3].line_length,
			&map->img[3].endian);
	map->img[4].img = mlx_xpm_file_to_image(map->mlx, "assets/P_up.xpm",
			&img_width, &img_height);
		map->img[4].addr = mlx_get_data_addr(map->img[4].img,
			&map->img[4].bits_per_pixel, &map->img[4].line_length,
			&map->img[4].endian);
	map->img[5].img = mlx_xpm_file_to_image(map->mlx, "assets/P_down.xpm",
			&img_width, &img_height);
	map->img[5].addr = mlx_get_data_addr(map->img[5].img,
			&map->img[5].bits_per_pixel, &map->img[5].line_length,
			&map->img[5].endian);
	load_img_3(map);
}

void	load_img(t_map *map)
{
	int		img_width;
	int		img_height;

	map->img[0].img = mlx_xpm_file_to_image(map->mlx, "assets/0.xpm",
			&img_width, &img_height);
	map->img[0].addr = mlx_get_data_addr(map->img[0].img,
			&map->img[0].bits_per_pixel, &map->img[0].line_length,
			&map->img[0].endian);
	map->img[1].img = mlx_xpm_file_to_image(map->mlx, "assets/1.xpm",
			&img_width, &img_height);
	map->img[1].addr = mlx_get_data_addr(map->img[1].img,
			&map->img[1].bits_per_pixel, &map->img[1].line_length,
			&map->img[1].endian);
	map->img[2].img = mlx_xpm_file_to_image(map->mlx, "assets/C.xpm",
			&img_width, &img_height);
	map->img[2].addr = mlx_get_data_addr(map->img[2].img,
			&map->img[2].bits_per_pixel, &map->img[2].line_length,
			&map->img[2].endian);
	load_img_2(map);
}
