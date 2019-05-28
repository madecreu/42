/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:48:26 by acastryc          #+#    #+#             */
/*   Updated: 2017/11/29 19:44:25 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_map(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->x)
	{
		j = -1;
		while (++j < map->x)
		{
			ft_putchar_fd(map->map[i][j], 1);
		}
		ft_putchar_fd('\n', 1);
	}
}
