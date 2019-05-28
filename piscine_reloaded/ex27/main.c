/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:32:16 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/07 22:03:20 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	reader(int fd)
{
	char	buffer[1];

	while (read(fd, buffer, 1) > 0)
		write(1, buffer, 1);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac < 2)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	reader(fd);
	close(fd);
	return (0);
}
