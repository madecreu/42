/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:23:24 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/06 14:02:07 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int		main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;
	int		fd;

	if (ac != 2)
		ft_putendl("Usage : ./fdf [file]");
	else
	{
		map = reader(av[1]);
		fd = open(av[1], O_RDONLY);
		map = fill_map(map, fd);
		close(fd);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "FdF");
		draw_map(mlx, map);
		mlx_hook(mlx.win, 2, 0, &event, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
