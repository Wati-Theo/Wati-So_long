/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:32:20 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/10 14:14:52 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	check_sprites(void)
{
	if (open("assets/0.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/1.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/C.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/E.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/P_down.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/P_left.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/P_right.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
	if (open("assets/P_up.xpm", O_RDONLY) < 0)
		wati_exit("Image_load_problem", 0);
}

void	wati_exit(char	*error, int cas)
{
	if (cas == 0)
	{
		write(2, "Error\n", 6);
		perror(error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	click_exit(t_map *map)
{
	(void)map;
	exit(EXIT_SUCCESS);
	return (0);
}

int	check_path(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len > 5)
		if (path[len - 4] == '.' && path[len - 3] == 'b' && path[len - 2] == 'e'
			&& path[len - 1] == 'r')
			return (0);
	wati_exit("Invalide_Map_Filename", 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	map.nb_boost = 0;
	map.current_boost = 0;
	map.nb_moves = 0;
	check_sprites();
	(void)argv;
	if (argc != 2 || check_path(argv[1]))
	{
		wati_exit("Arg_err", 0);
	}
	map.last_pos = 'f';
	map.mlx = mlx_init();
	load_img(&map);
	wati_parser(argv[1], &map);
	map.mlx_win = mlx_new_window(map.mlx, map.length * 64, map.height * 64,
			"./so_long");
	map.screen.img = mlx_new_image(map.mlx, map.length * 64, map.height * 64);
	map.screen.addr = mlx_get_data_addr(map.screen.img,
			&map.screen.bits_per_pixel, &map.screen.line_length,
			&map.screen.endian);
	mlx_hook(map.mlx_win, 2, 0, &read_input, &map);
	mlx_hook(map.mlx_win, 17, 0, &click_exit, &map);
	disp_map(&map);
	mlx_loop(map.mlx);
}
