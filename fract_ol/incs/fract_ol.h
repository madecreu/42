/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:40:15 by madecreu          #+#    #+#             */
/*   Updated: 2018/08/05 01:40:24 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# include <stdio.h>

# include "../libft/libft.h"

typedef struct		s_mlx
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	int		*src;
	int		*size;
}					t_mlx;

typedef struct		s_frac
{
	double	z;
	double	s_x;
	double	s_y;
	int		i;
	double	p_i;
	double	p_r;
}					t_frac;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_img
{
	int			x;
	int			y;
	int			bpp;
	int			h;
	int			w;
	int			end;
	int			sl;
	char		*str;
	void		*ptr;
	int			frac;
	int			clic;
	t_point		c;
	int			it;
	char		*ite;
}					t_img;

typedef struct		s_a
{
	t_mlx		mlx;
	t_frac		frac;
	t_img		img;
}					t_a;

int					colori(int i);
int					event(int keycode, void *param);
int					event_mandel(int keycode, void *param);
int					event_mandel2(int keycode, void *param);
int					event_mandel3(int keycode, void *param);
int					event_mandel4(int keycode, void *param);
int					event_mandel5(int keycode, void *param);
int					event_julia(int keycode, void *param);
int					event_julia2(int keycode, void *param);
int					event_julia3(int keycode, void *param);
int					event_julia4(int keycode, void *param);
int					event_julia5(int keycode, void *param);
int					event_burning(int keycode, void *param);
int					event_burning2(int keycode, void *param);
int					event_burning3(int keycode, void *param);
int					event_burning4(int keycode, void *param);
int					event_burning5(int keycode, void *param);
int					event_tricorn(int keycode, void *param);
int					event_tricorn2(int keycode, void *param);
int					event_tricorn3(int keycode, void *param);
int					event_tricorn4(int keycode, void *param);
int					event_tricorn5(int keycode, void *param);
int					event_mouse_press(int button, int x, int y, void *param);
int					event_mouse_release(int button, int x, int y, void *param);
int					event_mouse_move(int x, int y, void *param);
void				draw_frac(t_a *a);
void				draw_mandelbrot(t_mlx mlx, t_img img, t_frac frac);
void				draw_julia(t_mlx mlx, t_img img, t_frac frac);
void				draw_burning(t_mlx mlx, t_img img, t_frac frac);
void				draw_tricorn(t_mlx mlx, t_img img, t_frac frac);
void				pixel_put(t_img img, int x, int y, int color);
t_img				create_img(t_mlx mlx);
t_frac				init_mandel(t_frac frac);
t_frac				init_julia(t_frac frac);
t_frac				init_burning(t_frac frac);
t_frac				init_tricorn(t_frac frac);
t_frac				init_frac(void);

#endif
