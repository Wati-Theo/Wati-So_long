/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_So_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:42:37 by tschlege          #+#    #+#             */
/*   Updated: 2022/04/21 14:44:48 by tschlege         ###   ########lyon.fr   */
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
	char	*map;
	t_data	img;
}	t_map;

void	wati_exit(char	*error);
void	wati_parser(char *path, t_map *map);
void	display(t_map *map);

#endif