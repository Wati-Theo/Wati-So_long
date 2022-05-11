/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_So_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:42:37 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/11 14:52:28 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATI_SO_LONG_H
# define WATI_SO_LONG_H

# include "mlx/mlx.h"
# include "Wati-Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map {
	void	*mlx;
	void	*mlx_win;
	int		length;
	int		height;
	int		last_pos;
	int 	current_boost;
	int		nb_boost;
	int		nb_moves;
	int		nb_Player;
	char	*map;
	t_data	img[8];
	t_data	screen;
}	t_map;

void	wati_exit(char	*error, int cas);
void	wati_parser(char *path, t_map *map);
void	disp_map(t_map *map);
void	load_img(t_map *map);
void	test(t_map *map);
int		read_input(int keycode, t_map *map);

#endif