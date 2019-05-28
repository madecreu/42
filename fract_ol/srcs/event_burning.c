/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_burning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:55:12 by madecreu          #+#    #+#             */
/*   Updated: 2018/05/11 18:55:13 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

int		event_burning(int keycode, void *param)
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
		a->frac.s_y += 0.05 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	else if (keycode == 125)
	{
		a->frac.s_y -= 0.05 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	return (event_burning2(keycode, param));
}

int		event_burning2(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 124)
	{
		a->frac.s_x -= 0.05 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	else if (keycode == 123)
	{
		a->frac.s_x += 0.05 / a->frac.z;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	else if (keycode == 69)
	{
		a->frac.z *= 1.05;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	return (event_burning3(keycode, param));
}

int		event_burning3(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 78)
	{
		if (a->frac.z / 1.05 > 0)
			a->frac.z /= 1.05;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	else if (keycode == 116)
	{
		a->frac.i++;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	else if (keycode == 121)
	{
		a->frac.i--;
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	return (event_burning4(keycode, param));
}

int		event_burning4(int keycode, void *param)
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
	else if (keycode == 83)
	{
		a->img.frac = 1;
		a->frac = init_julia(a->frac);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_julia(a->mlx, a->img, a->frac);
	}
	else if (keycode == 15)
	{
		a->frac = init_burning(a->frac);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
	}
	return (event_burning5(keycode, param));
}

int		event_burning5(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	if (keycode == 34)
	{
		a->img.it = (a->img.it == 0 ? 1 : 0);
		ft_bzero(a->img.str, a->img.w * a->img.h * 4);
		draw_burning(a->mlx, a->img, a->frac);
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
