/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:09:17 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/15 13:36:26 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_cast;
	unsigned char		*src_cast;

	i = 0;
	dst_cast = (unsigned char*)dst;
	src_cast = (unsigned char*)src;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		if (src_cast[i] == (unsigned char)c)
			return (&dst_cast[i + 1]);
		i++;
	}
	return (NULL);
}
