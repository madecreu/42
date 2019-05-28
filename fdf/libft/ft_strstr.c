/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:32:59 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/10 17:34:08 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (haystack[i] && needle[n])
	{
		if (haystack[i + n] == needle[n])
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
