/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:37:36 by madecreu          #+#    #+#             */
/*   Updated: 2017/12/01 17:52:57 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buffer(char **buf, char **line)
{
	char *tmp;

	if (**buf == '\0')
		return (0);
	if ((tmp = ft_strchr(*buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strndup(*buf, tmp - *buf + 1);
		*buf = tmp + 1;
		return (1);
	}
	tmp = ft_strchr(*buf, '\0');
	*line = ft_strndup(*buf, tmp - *buf + 1);
	*buf = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buf = NULL;
	char			readbuf[BUFF_SIZE + 1];
	int				size;

	if (line == NULL || fd < 0)
		return (-1);
	if (buf && (size = check_buffer(&buf, line)))
		return (size);
	while ((size = read(fd, readbuf, BUFF_SIZE)))
	{
		if (size <= 0)
			return (size);
		readbuf[size] = '\0';
		if (!buf)
			buf = ft_strdup(readbuf);
		else
			buf = ft_strjoinf(buf, &readbuf[0]);
	}
	if (buf && check_buffer(&buf, line))
		return (1);
	return (0);
}
