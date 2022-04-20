/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:32:20 by tschlege          #+#    #+#             */
/*   Updated: 2022/04/20 21:47:26 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_So_long.h"

void	wati_exit(char	*error)
{
	write(2, "Error\n", 6);
	perror(error);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	(void)argv;
	if (argc != 2)
	{
		wati_exit("Arg_err");
	}
	wati_parser(argv[1], &map);
}
