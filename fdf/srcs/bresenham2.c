/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:27:00 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/12 18:29:50 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	octant5(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.x;
	d.x *= 2;
	d.y *= 2;
	while (c1.x >= c2.x)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err -= d.y;
		if (err >= 0)
		{
			c1.y--;
			err += d.x;
		}
		c1.x--;
	}
}

void	octant6(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.y;
	d.x *= 2;
	d.y *= 2;
	while (c1.y >= c2.y)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err -= d.x;
		if (err >= 0)
		{
			c1.x--;
			err += d.y;
		}
		c1.y--;
	}
}

void	octant7(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.y;
	d.x *= 2;
	d.y *= 2;
	while (c1.y >= c2.y)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err += d.x;
		if (err > 0)
		{
			c1.x++;
			err += d.y;
		}
		c1.y--;
	}
}

void	octant8(t_mlx mlx, t_point d, t_point c1, t_point c2)
{
	int err;

	err = d.x;
	d.x *= 2;
	d.y *= 2;
	while (c1.x <= c2.x)
	{
		(void)mlx_pixel_put(mlx.mlx, mlx.win, c1.x, c1.y, 0x0000FF);
		err += d.y;
		if (err < 0)
		{
			c1.y--;
			err += d.x;
		}
		c1.x++;
	}
}
