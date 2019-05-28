/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:28:12 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/30 21:47:00 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *res_src;
	unsigned char *res_dst;

	res_src = (unsigned char*)src;
	res_dst = (unsigned char*)dst;
	if (res_src < res_dst)
	{
		while (n > 0)
		{
			res_dst[n - 1] = res_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (res_dst);
}
