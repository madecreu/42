/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:54:57 by madecreu          #+#    #+#             */
/*   Updated: 2018/05/11 18:55:00 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

int		event_julia(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 53)
	{
		free(a->img.str);
		exit(3);
	}
	else if (keycode == 126)
	{
		a->frac.s_y += 5 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 125)
	{
		a->frac.s_y -= 5 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	return (event_julia2(keycode, param));
}

int		event_julia2(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 124)
	{
		a->frac.s_x -= 5 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 123)
	{
		a->frac.s_x += 5 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 69)
	{
		a->frac.z *= 1.05;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	return (event_julia3(keycode, param));
}

int		event_julia3(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 78)
	{
		if (a->frac.z / 1.05 > 0)
			a->frac.z /= 1.05;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 116)
	{
		a->frac.i++;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 121)
	{
		a->frac.i--;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	return (event_julia4(keycode, param));
}

int		event_julia4(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 82)
	{
		a->img.frac = 0;
		a->frac = init_mandel(a->frac);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_mandelbrot(a->mlx, a->img, a->frac);
	}
	else if (keycode == 84)
	{
		a->img.frac = 2;
		a->frac = init_burning(a->frac);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	else if (keycode == 15)
	{
		a->frac = init_julia(a->frac);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	return (event_julia5(keycode, param));
}

int		event_julia5(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 34)
	{
		a->img.it = (a->img.it == 0 ? 1 : 0);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 85)
	{
		a->img.frac = 3;
		a->frac = init_tricorn(a->frac);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_tricorn(a->mlx, a->img, a->frac);
	}
	return (0);
}
