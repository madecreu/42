/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:02:05 by acastryc          #+#    #+#             */
/*   Updated: 2017/12/02 14:42:41 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int result;
	int index;
	int odd;

	result = 0;
	index = 0;
	odd = 1;
	while (result <= nb)
	{
		result += odd;
		odd += 2;
		index++;
	}
	return (index - 1);
}

t_map	*ft_create_map(t_etris *tab)
{
	int		i;
	int		size;
	int		nb_pieces;
	t_map	*map;

	map = NULL;
	i = -1;
	nb_pieces = ft_tablen(tab);
	size = ft_sqrt(nb_pieces * 4);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_display_error();
	if (!(map->map = (char **)malloc(sizeof(char *) * size)))
		ft_display_error();
	map->x = size;
	while (++i < map->x)
		if (!(map->map[i] = (char *)malloc(sizeof(char) * map->x)))
			ft_display_error();
	return (map);
}
