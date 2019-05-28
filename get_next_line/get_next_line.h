/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:35:13 by madecreu          #+#    #+#             */
/*   Updated: 2017/12/12 15:12:51 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

# include "libft/libft.h"
# include <unistd.h>

int		get_next_line(const int fd, char **line);
int		check_buffer(char **buf, char **line);

#endif
