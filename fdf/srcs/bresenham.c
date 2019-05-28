/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:21:05 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/12 17:44:46 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	bresenham(t_mlx mlx, t_point c1, t_point c2)
{
	t_point d;

	d.x = c2.x - c1.x;
	d.y = c2.y - c1.y;
	if (d.x > 0 && d.y >= 0 && d.x >= d.y)
		octant1(mlx, d, c1, c2);
	if (d.x >= 0 && d.y > 0 && d.x < d.y)
		octant2(mlx, d, c1, c2);
	if (d.x > 0 && d.y < 0 && d.x >= -d.y)
		octant8(mlx, d, c1, c2);
	if (d.x >= 0 && d.y < 0 && d.x < -d.y)
		octant7(mlx, d, c1, c2);
	if (d.x <= 0 && d.y > 0 && -d.x >= d.y)
		octant4(mlx, d, c1, c2);
	if (d.x < 0 && d.y > 0 && -d.x < d.y)
		octant3(mlx, d, c1, c2);
	if (d.x < 0 && d.y < 0 && d.x <= d.y)
		octant5(mlx, d, c1, c2);
	if (d.x < 0 && d.y < 0 && d.x > d.y)
		octant6(mlx, d, c1, c2);
}

void	octant1(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.x;
	d.x *= 2;
	d.y *= 2;
	while (c1.x <= c2.x)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err -= d.y;
		if (err < 0)
		{
			c1.y++;
			err += d.x;
		}
		c1.x++;
	}
}

void	octant2(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.y;
	d.x *= 2;
	d.y *= 2;
	while (c1.y <= c2.y)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err -= d.x;
		if (err < 0)
		{
			c1.x++;
			err += d.y;
		}
		c1.y++;
	}
}

void	octant3(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.y;
	d.x *= 2;
	d.y *= 2;
	while (c1.y <= c2.y)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err += d.x;
		if (err <= 0)
		{
			c1.x--;
			err += d.y;
		}
		c1.y++;
	}
}

void	octant4(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.x;
	d.x *= 2;
	d.y *= 2;
	while (c1.x >= c2.x)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err += d.y;
		if (err >= 0)
		{
			c1.y++;
			err += d.x;
		}
		c1.x--;
	}
}
