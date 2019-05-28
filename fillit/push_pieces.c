/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:14:10 by madecreu          #+#    #+#             */
/*   Updated: 2017/12/02 17:14:56 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*delete_pieces(t_map *map, int alpha)
{
	t_point coor;

	coor.y = -1;
	while (++(coor.y) < map->x)
	{
		coor.x = -1;
		while (++(coor.x) < map->x)
		{
			if (map->map[coor.y][coor.x] == 'A' + alpha)
				map->map[coor.y][coor.x] = '.';
		}
	}
	return (map);
}

t_map		*push_pieces(t_point pos, t_etris pieces, t_map *map, int alpha)
{
	map->map[pos.y][pos.x] = 'A' + alpha;
	pos.y = pos.y + pieces.pi_pos[1].y;
	pos.x = pos.x + pieces.pi_pos[1].x;
	map->map[pos.y][pos.x] = 'A' + alpha;
	pos.y = pos.y + pieces.pi_pos[2].y;
	pos.x = pos.x + pieces.pi_pos[2].x;
	map->map[pos.y][pos.x] = 'A' + alpha;
	pos.y = pos.y + pieces.pi_pos[3].y;
	pos.x = pos.x + pieces.pi_pos[3].x;
	map->map[pos.y][pos.x] = 'A' + alpha;
	return (map);
}

int			try_to_push(t_point pi, t_point *pi_pos, t_map *map)
{
	if (pi.y < map->x && pi.x < map->x && map->map[pi.y][pi.x] == '.')
	{
		pi.y += pi_pos[1].y;
		pi.x += pi_pos[1].x;
		if (pi.y < map->x && pi.x < map->x && map->map[pi.y][pi.x] == '.')
		{
			pi.y += pi_pos[2].y;
			pi.x += pi_pos[2].x;
			if (pi.y < map->x && pi.x < map->x && map->map[pi.y][pi.x] == '.')
			{
				pi.y += pi_pos[3].y;
				pi.x += pi_pos[3].x;
				if (pi.y < map->x && pi.x < map->x
						&& map->map[pi.y][pi.x] == '.')
					return (1);
			}
		}
	}
	return (0);
}
