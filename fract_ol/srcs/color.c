/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:13:29 by madecreu          #+#    #+#             */
/*   Updated: 2018/05/11 17:13:31 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

int		colori(int i)
{
	return (i * 3 * 0x00FF00);
}

t_frac	init_frac(void)
{
	t_frac frac;

	frac.z = 0;
	frac.s_x = 0;
	frac.s_y = 0;
	frac.i = 0;
	frac.p_i = 0;
	frac.p_r = 0;
	return (frac);
}
