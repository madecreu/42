/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:08:52 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/08 16:08:54 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	draw_map(t_mlx mlx, t_map map)
{
	t_point i;
	t_point	coor1;
	t_point coor2;
	t_point	coor3;

	i.y = 0;
	mlx_pixel_put(mlx.mlx, mlx.win, 960, 50, 0x0000FF);
	while (i.y + 1 < map.height)
	{
		i.x = 0;
		while (i.x + 1 < map.width)
		{
			coor1.x = 960 + ((i.x - i.y) * TWH);
			coor1.y = 50 + ((i.x + i.y) * THH) - map.map[i.y + 1][i.x];
			coor2.x = 960 + ((i.x + 1 - i.y) * TWH);
			coor2.y = 50 + ((i.x + 1 + i.y) * THH) - map.map[i.y + 1][i.x + 1];
			coor3.x = 960 + ((i.x - (i.y - 1)) * TWH);
			coor3.y = 50 + ((i.x + (i.y - 1)) * THH) - map.map[i.y][i.x];
			bresenham(mlx, coor1, coor2);
			bresenham(mlx, coor1, coor3);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
}
