/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:59:26 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/12 15:54:05 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
