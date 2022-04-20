/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_So_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:42:37 by tschlege          #+#    #+#             */
/*   Updated: 2022/04/20 21:53:03 by tschlege         ###   ########lyon.fr   */
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

typedef struct s_map
{
	int		length;
	int		height;
	char	*map;
}	t_map;

void	wati_exit(char	*error);
void	wati_parser(char *path, t_map *map);

#endif