/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:04:19 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/14 18:49:18 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	while (dst[i] && size)
	{
		i++;
		size--;
	}
	len = 0;
	while (src[len])
	{
		if (size > 1)
		{
			dst[i + len] = src[len];
			dst[i + len + 1] = '\0';
			size--;
		}
		len++;
	}
	return (len + i);
}
