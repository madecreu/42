/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:34:28 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/12 19:18:19 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define TILE_HEIGHT		4
# define TILE_WIDTH			8
# define THH				TILE_HEIGHT / 2
# define TWH				TILE_WIDTH / 2

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	int		width;
	int		height;
	int		**map;
}					t_map;

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

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

t_map				reader(char *file);
t_map				malloc_map(int nb_int, int nb_line);
t_map				reader_controler(int fd, int nb_int);
t_map				fill_map(t_map map, int fd);
int					parser(char *ret, int i, int nb_int);
int					event(int keycode, void *param);
void				draw_map(t_mlx mlx, t_map map);
void				error();
void				bresenham(t_mlx mlx, t_point c1, t_point c2);
void				octant1(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant2(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant3(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant4(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant5(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant6(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant7(t_mlx mlx, t_point d, t_point c1, t_point c2);
void				octant8(t_mlx mlx, t_point d, t_point c1, t_point c2);

#endif
