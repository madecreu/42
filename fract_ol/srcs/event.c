/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:34:10 by madecreu          #+#    #+#             */
/*   Updated: 2018/05/07 18:34:12 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

void	draw_frac(t_a *a)
{
	if (a->img.frac == 0)
		draw_mandelbrot(a->mlx, a->img, a->frac);
	else if (a->img.frac == 1)
		draw_julia(a->mlx, a->img, a->frac);
	else if (a->img.frac == 2)
		draw_burning(a->mlx, a->img, a->frac);
	else
		draw_tricorn(a->mlx, a->img, a->frac);
}

int		event(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (a->img.frac == 0)
		event_mandel(keycode, param);
	else if (a->img.frac == 1)
		event_julia(keycode, param);
	else if (a->img.frac == 2)
		event_burning(keycode, param);
	else
		event_tricorn(keycode, param);
	return (0);
}
