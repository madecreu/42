/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:53:15 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/30 19:51:40 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*cpy_map(t_map *new, t_map *map)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < new->x)
	{
		ft_bzero(new->map[i], (size_t)(new->x));
		i++;
	}
	i = 0;
	while (i < map->x)
	{
		while (n < map->x)
		{
			new->map[i][n] = map->map[i][n];
			n++;
		}
		new->map[i][n] = '.';
		n = 0;
		i++;
	}
	new->map[i] = ft_memset(new->map[i], '.', new->x);
	return (new);
}

t_map	*resize_map(t_map *map)
{
	int		i;
	t_map	*new;

	if (!(new = (t_map*)malloc(sizeof(t_map))))
		ft_display_error();
	new->x = map->x + 1;
	if (!(new->map = (char**)malloc(sizeof(char*) * (new->x + 1))))
		ft_display_error();
	i = 0;
	while (i < new->x)
	{
		if (!(new->map[i] = (char*)malloc(new->x + 1)))
			ft_display_error();
		i++;
	}
	new->map[i] = NULL;
	new = cpy_map(new, map);
	i = 0;
	while (i < map->x)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	return (new);
}
