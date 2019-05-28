/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:22:47 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/11 15:42:04 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int mem;

	i = 0;
	mem = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			mem = i;
		i++;
	}
	if (c == 0)
		return ((char*)&s[i]);
	if (mem == -1)
		return (NULL);
	else
		return ((char*)&s[mem]);
}
