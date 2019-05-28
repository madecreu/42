/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:00:10 by madecreu          #+#    #+#             */
/*   Updated: 2018/05/09 19:00:12 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

void	calc_burning(t_frac frac, t_img img, t_point coor, double p_i)
{
	double	p_r;
	double	new_r;
	double	new_i;
	double	tmp;
	int		i;

	p_r = 1.5 * (coor.x - img.w / 2.0) / (0.5 * frac.z * img.w) + frac.s_x;
	new_r = 0;
	new_i = 0;
	tmp = 0;
	i = 0;
	while (new_r * new_r + new_i * new_i < 4.0 && i < frac.i)
	{
		tmp = new_r;
		new_r = fabs(new_r * new_r - new_i * new_i + p_r);
		new_i = fabs(2.0 * tmp * new_i + p_i);
		i++;
	}
	if (i == frac.i)
		pixel_put(img, coor.x, coor.y, 0x000000);
	else
		pixel_put(img, coor.x, coor.y, colori(i));
}

t_frac	init_burning(t_frac frac)
{
	frac.z = 0.8;
	frac.s_x = -0.75;
	frac.s_y = 0.0;
	frac.i = 10;
	return (frac);
}

void	draw_burning(t_mlx mlx, t_img img, t_frac frac)
{
	double	p_i;
	t_point coor;

	coor.y = 0;
	while (coor.y < img.h)
	{
		p_i = (coor.y - img.h / 2.0) / (0.5 * frac.z * img.h) + frac.s_y;
		coor.x = 0;
		while (coor.x < img.w)
		{
			calc_burning(frac, img, coor, p_i);
			coor.x++;
		}
		coor.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.ptr, 0, 0);
	mlx_string_put(mlx.mlx, mlx.win, 420, 0, 0XFFFFFF, "Burning_Ship");
	if (img.it == 1)
	{
		img.ite = ft_itoa(frac.i);
		mlx_string_put(mlx.mlx, mlx.win, 0, 0, 0XFFFFFF, img.ite);
		free(img.ite);
	}
}
