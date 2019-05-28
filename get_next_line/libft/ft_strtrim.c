/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:24:35 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/13 18:57:17 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		functionkifechie(char const *s, size_t n)
{
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n--;
	return (n);
}

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		n;
	size_t		c;
	char		*res;

	if (!s)
		return (NULL);
	i = 0;
	c = 0;
	n = ft_strlen((char*)s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	n = functionkifechie(s, n);
	if (!(res = (char*)malloc(sizeof(char) * (n - i + 2))))
		return (NULL);
	while (i <= n)
	{
		res[c] = s[i];
		i++;
		c++;
	}
	res[c] = '\0';
	return (res);
}
