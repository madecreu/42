/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:22:44 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/12 16:08:32 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill(char *res, long n, int len)
{
	int i;
	int c;

	c = len;
	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		i++;
		n *= -1;
	}
	len--;
	while (n >= 10)
	{
		res[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	res[i] = n + 48;
	res[c] = '\0';
	i = 0;
	return (res);
}

char			*ft_itoa(int n)
{
	int		temp;
	int		len;
	char	*res;

	temp = n;
	len = 0;
	if (temp <= 0)
		len++;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (fill(res, (long)n, len));
}
