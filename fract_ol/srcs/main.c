/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:36:34 by madecreu          #+#    #+#             */
/*   Updated: 2018/08/05 01:38:32 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fract_ol.h"

void	affich_opt(void)
{
	ft_putstr(" ______________________________________________ \n");
	ft_putstr("/                                              \\\n");
	ft_putstr("| Arrows / Left clic :                    Move |\n");
	ft_putstr("| '+' or '-' / mouse wheel :              Zoom |\n");
	ft_putstr("| 'page up' or 'page down' :         Iteration |\n");
	ft_putstr("| 'r' :                          Reset fractal |\n");
	ft_putstr("| '0', '1', '2' or '3' :        Change fractal |\n");
	ft_putstr("| 'i' :                        Show iterations |\n");
	ft_putstr("\\______________________________________________/\n");
}

t_a		check_param(int ac, char **av, t_a a)
{
	if (ac == 2 && !(ft_strcmp(ft_strlowcase(av[1]), "mandelbrot")))
	{
		a.frac = init_mandel(a.frac);
		draw_mandelbrot(a.mlx, a.img, a.frac);
		a.img.frac = 0;
	}
	else if (ac == 2 && !(ft_strcmp(ft_strlowcase(av[1]), "julia")))
	{
		a.frac = init_julia(a.frac);
		draw_julia(a.mlx, a.img, a.frac);
		a.img.frac = 1;
	}
	else if (ac == 2 && !(ft_strcmp(ft_strlowcase(av[1]), "burning_ship")))
	{
		a.frac = init_burning(a.frac);
		draw_burning(a.mlx, a.img, a.frac);
		a.img.frac = 2;
	}
	else
	{
		ft_putstr("Usage : ./fractol [fractale]\nFractale available :\n");
		ft_putstr("Mandelbrot\nJulia\nBurning_Ship\n");
		exit(3);
	}
	return (a);
}

t_img	create_img(t_mlx mlx)
{
	t_img img;

	img.x = 0;
	img.y = 0;
	img.w = 960;
	img.h = 540;
	img.it = 0;
	img.frac = 0;
	img.ptr = mlx_new_image(mlx.mlx, img.w, img.h);
	img.str = mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.end);
	return (img);
}

void	pixel_put(t_img img, int x, int y, int color)
{
	int		i;

	if (x < img.w && y < img.h && x >= 0 && y >= 0)
	{
		i = x * (img.bpp / 8) + y * img.sl;
		img.str[i] = color;
		img.str[i + 1] = color >> 8;
		img.str[i + 2] = color >> 16;
	}
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_a		a;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 960, 540, "Fract_ol");
	a.mlx = mlx;
	a.img = create_img(mlx);
	a.frac = init_frac();
	a = check_param(ac, av, a);
	affich_opt();
	mlx_hook(mlx.win, 4, 0, &event_mouse_press, &a);
	mlx_hook(mlx.win, 5, 0, &event_mouse_release, &a);
	mlx_hook(mlx.win, 6, 0, &event_mouse_move, &a);
	mlx_hook(mlx.win, 2, 0, &event, &a);
	mlx_loop(mlx.mlx);
}
