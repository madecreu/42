/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onreessaye.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:25:52 by madecreu          #+#    #+#             */
/*   Updated: 2017/12/02 17:14:18 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*traitement(t_point *pi_pos)
{
	pi_pos[3].x = pi_pos[3].x - pi_pos[2].x;
	pi_pos[3].y = pi_pos[3].y - pi_pos[2].y;
	pi_pos[2].x = pi_pos[2].x - pi_pos[1].x;
	pi_pos[2].y = pi_pos[2].y - pi_pos[1].y;
	pi_pos[1].x = pi_pos[1].x - pi_pos[0].x;
	pi_pos[1].y = pi_pos[1].y - pi_pos[0].y;
	return (pi_pos);
}

t_point		*pos_piece(char *piece, t_point *pi_pos)
{
	int		i;
	int		n;
	t_point	pos;

	i = -1;
	n = -1;
	pos.x = -1;
	pos.y = 0;
	while (piece[++i])
	{
		++pos.x;
		if (piece[i] == '\n')
		{
			pos.y++;
			pos.x = -1;
		}
		else if (piece[i] == '#')
		{
			n++;
			pi_pos[n].y = pos.y;
			pi_pos[n].x = pos.x;
		}
	}
	return (traitement(pi_pos));
}
