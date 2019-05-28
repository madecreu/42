/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:06:03 by acastryc          #+#    #+#             */
/*   Updated: 2017/12/02 18:00:19 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_etris	*tab;
	t_point	init;
	t_map	*map;
	int		i;

	i = -1;
	if (argc != 2)
		write(1, "usage: fillit source_file\n", 26);
	else
	{
		tab = NULL;
		map = NULL;
		init.x = 0;
		init.y = 0;
		fd = open(argv[1], O_RDONLY);
		tab = ft_check_tetris(fd, i);
		map = ft_map(ft_create_map(tab));
		while (!(the_backtrack(map, tab, 0)))
			map = resize_map(map);
		ft_print_map(map);
	}
	return (0);
}
