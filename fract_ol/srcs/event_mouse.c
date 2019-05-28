/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:26:00 by madecreu          #+#    #+#             */
/*   Updated: 2018/05/11 19:26:02 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

int		event_mouse_move(int x, int y, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (a->img.clic == 1)
	{
		a->frac.p_i += (y - a->img.c.y) * 0.001;
		a->frac.p_r += (x - a->img.c.x) * 0.001;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
		a->img.c.x = x;
		a->img.c.y = y;
	}
	if (a->img.clic == 2)
	{
		a->frac.s_y -= (y - a->img.c.y) * 0.005;
		a->frac.s_x -= (x - a->img.c.x) * 0.005;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		a->img.c.x = x;
		a->img.c.y = y;
		draw_frac(a);
	}
	return (0);
}

int		event_mouse_release(int button, int x, int y, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	(void)x;
	(void)y;
	if (button == 1 || button == 2)
		a->img.clic = 0;
	return (0);
}

int		event_mouse_press2(int button, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (button == 5)
	{
		a->frac.z *= 1.05;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_frac(a);
	}
	if (button == 4)
	{
		if (a->frac.z / 1.05 > 0)
		{
			a->frac.z /= 1.05;
			ft_bzero(a->img.str, a->img.w * a->img.h * 4);
			draw_frac(a);
		}
	}
	return (0);
}

int		event_mouse_press(int button, int x, int y, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (a->img.frac == 1 && button == 1)
	{
		a->img.clic = 1;
		a->img.c.x = x;
		a->img.c.y = y;
	}
	if (button == 2)
	{
		a->img.clic = 2;
		a->img.c.x = x;
		a->img.c.y = y;
	}
	return (event_mouse_press2(button, param));
}
