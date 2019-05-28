/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:44:35 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/11 15:45:03 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	while (haystack[i] && needle[n] && i < len)
	{
		if (haystack[i + n] == needle[n] && (i + n) < len)
			n++;
		else
		{
			n = 0;
			i++;
		}
	}
	if (needle[n] == '\0')
		return ((char *)&(haystack[i]));
	return (NULL);
}
