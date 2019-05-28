/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:25:03 by madecreu          #+#    #+#             */
/*   Updated: 2017/12/04 16:25:07 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		n;

	i = -1;
	n = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++n])
		res[i + n] = s2[n];
	res[i + n] = '\0';
	if (*s1)
		free(s1);
	return (res);
}
