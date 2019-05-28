/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:45:57 by acastryc          #+#    #+#             */
/*   Updated: 2017/11/29 12:20:22 by acastryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Save a copy of  string
*/

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(*s2) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
