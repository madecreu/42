/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:06:56 by acastryc          #+#    #+#             */
/*   Updated: 2017/12/02 18:00:31 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_hashlink(char *piece)
{
	int		i;
	int		linkcount;

	i = 0;
	linkcount = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (i >= 5 && piece[i - 5] == '#')
				linkcount++;
			if (i < 20 && piece[i + 1] == '#')
				linkcount++;
			if (piece[i - 1] == '#')
				linkcount++;
			if (i <= 15 && piece[i + 5] == '#')
				linkcount++;
		}
		i++;
	}
	if (linkcount == 8 || linkcount == 6)
		return (1);
	return (0);
}

int		ft_check_valid(char *piece)
{
	int		i;
	int		hashcount;
	int		pointcount;

	i = 0;
	hashcount = 0;
	pointcount = 0;
	while (piece[i] == '\n' || piece[i] == '.' || piece[i] == '#')
	{
		if ((i + 1) % 5 == 0 && piece[i] != '\n')
			return (0);
		if (piece[i] == '#')
			hashcount++;
		if (piece[i] == '.')
			pointcount++;
		i++;
	}
	if (hashcount > 4 || pointcount > 12 || i != 20)
		return (0);
	return (1);
}

t_etris	*ft_check_tetris(int fd, int i)
{
	int		r;
	t_etris	*pi;
	char	buffer[21];

	ft_memset(buffer, '.', 20);
	buffer[20] = '\0';
	if (!(pi = (t_etris *)malloc(sizeof(t_etris) * 27)))
		return (NULL);
	while (++i < 26 && (r = read(fd, buffer, 20)) > 0)
	{
		buffer[r] = '\0';
		pi[i].pieces = ft_strdup(buffer);
		if (ft_check_valid(pi[i].pieces) == 0 || ft_hashlink(pi[i].pieces) == 0)
			ft_display_error();
		r = read(fd, buffer, 1);
		if (r != 0 && buffer[0] != '\n')
			ft_display_error();
		if (!(pi[i].pi_pos = (t_point *)malloc(sizeof(t_point) * 4)))
			ft_display_error();
		pi[i].pi_pos = pos_piece(pi[i].pieces, pi[i].pi_pos);
	}
	if (buffer[0] == '\n' || i == 0)
		ft_display_error();
	pi[i].pieces = NULL;
	return (pi);
}
