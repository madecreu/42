/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:35:51 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/07 17:36:20 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

t_map		fill_map(t_map map, int fd)
{
	char	*ret;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (get_next_line(fd, &ret) > 0)
	{
		x = 0;
		i = 0;
		while (ret[i] != '\0' && ret[i] != '\n')
		{
			while (ret[i] == ' ')
				i++;
			map.map[y][x] = ft_atoi(&ret[i]);
			while (ret[i] != ' ' && ret[i] != '\0')
				i++;
			x++;
		}
		y++;
		ft_memdel((void **)&ret);
	}
	close(fd);
	return (map);
}
