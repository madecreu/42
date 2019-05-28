/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:27:44 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/07 16:18:56 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

t_map		malloc_map(int nb_int, int nb_line)
{
	t_map	map;
	int		i;

	i = 0;
	map.width = nb_int;
	map.height = nb_line;
	if (!(map.map = (int**)malloc(sizeof(int*) * (map.height))))
		error(3);
	while (i < map.height)
	{
		if (!(map.map[i] = (int*)malloc(sizeof(int) * (map.width))))
			error(3);
		i++;
	}
	return (map);
}

int			parser(char *ret, int i, int nb_int)
{
	while (ret[i])
	{
		if (ret[i] == ' ')
			i++;
		else if (ret[i] == '-' || ret[i] == '+')
		{
			i++;
			if (ret[i] == '-' || ret[i] == '+' || ret[i] == ' ')
				error(1);
		}
		else if (ret[i] >= '0' && ret[i] <= '9')
		{
			nb_int++;
			while (ret[i] >= '0' && ret[i] <= '9')
				i++;
		}
		else
			error(0);
	}
	free(ret);
	ret = NULL;
	return (nb_int);
}

t_map		reader_controler(int fd, int nb_int)
{
	char	*ret;
	int		nb_line;
	int		nb_int_here;

	nb_line = 1;
	while (get_next_line(fd, &ret) > 0)
	{
		nb_int_here = parser(ret, 0, 0);
		if (nb_int == nb_int_here)
			nb_line++;
		else
			error(2);
	}
	return (malloc_map(nb_int, nb_line));
}

t_map		reader(char *file)
{
	int		fd;
	char	*ret;
	int		nb_int;
	int		gnl_ret;

	fd = open(file, O_RDONLY);
	gnl_ret = get_next_line(fd, &ret);
	if (gnl_ret == -1)
		error(4);
	else if (gnl_ret == 0)
		error(5);
	nb_int = parser(ret, 0, 0);
	return (reader_controler(fd, nb_int));
}

void		error(int i)
{
	if (i == 0)
		ft_putendl("Faut pas mettre des lettres");
	if (i == 1)
		ft_putendl("apres un signe on met des chiffres");
	if (i == 2)
		ft_putendl("Ouais ouais y a pas le meme nombre de nombre par ligne");
	if (i == 3)
		ft_putendl("Le malloc tourne mal");
	if (i == 4)
		ft_putendl("Ce que tu envoie ne peut etre lu, genre un dossier");
	if (i == 5)
		ft_putendl("Ton fichier est vide, c'est triste");
	exit(3);
}
