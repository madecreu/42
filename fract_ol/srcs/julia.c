/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:41:58 by madecreu          #+#    #+#             */
/*   Updated: 2018/08/05 01:39:20 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

void	calc_julia(t_frac frac, t_img img, t_point coor)
{
	double	new_r;
	double	new_i;
	double	tmp;
	int		i;

	new_r = coor.x / frac.z + frac.s_x;
	new_i = coor.y / frac.z + frac.s_y;
	tmp = 0;
	i = 0;
	while (new_r * new_r + new_i * new_i < 4.0 && i < frac.i)
	{
		tmp = new_r;
		new_r = new_r * new_r - new_i * new_i + frac.p_r;
		new_i = 2.0 * tmp * new_i + frac.p_i;
		i++;
	}
	if (i == frac.i)
		pixel_put(img, coor.x, coor.y, 0x000000);
	else
		pixel_put(img, coor.x, coor.y, colori(i));
}

t_frac	init_julia(t_frac frac)
{
	frac.z = 200;
	frac.s_x = -2.4;
	frac.s_y = -1.30;
	frac.i = 10;
	frac.p_i = 0;
	frac.p_r = 0;
	return (frac);
}

void	draw_julia(t_mlx mlx, t_img img, t_frac frac)
{
	t_point coor;

	coor.y = 0;
	while (coor.y < img.h)
	{
		coor.x = 0;
		while (coor.x < img.w)
		{
			calc_julia(frac, img, coor);
			coor.x++;
		}
		coor.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.ptr, 0, 0);
	mlx_string_put(mlx.mlx, mlx.win, 455, 0, 0XFFFFFF, "Julia");
	if (img.it == 1)
	{
		img.ite = ft_itoa(frac.i);
		mlx_string_put(mlx.mlx, mlx.win, 0, 0, 0XFFFFFF, img.ite);
		free(img.ite);
	}
}
