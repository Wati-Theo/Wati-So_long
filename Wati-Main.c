/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:32:20 by tschlege          #+#    #+#             */
/*   Updated: 2022/04/21 14:44:58 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	wati_exit(char	*error)
{
	write(2, "Error\n", 6);
	perror(error);
	exit(EXIT_FAILURE);
}

int	check_path(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len > 5)
		if (path[len - 4] == '.' && path[len - 3] == 'b' && path[len - 2] == 'e'
			&& path[len - 1] == 'r')
			return (0);
	wati_exit("Invalide_Map_Filename");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	(void)argv;
	if (argc != 2 || check_path(argv[1]))
	{
		wati_exit("Arg_err");
	}
	wati_parser(argv[1], &map);
	display(&map);
}
