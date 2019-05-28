/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:29:21 by acastryc          #+#    #+#             */
/*   Updated: 2017/11/29 18:21:21 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Outputs the char c to the file descriptor fd
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
