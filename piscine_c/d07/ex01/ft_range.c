/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 02:50:51 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/15 01:30:34 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*res;
	int		len;

	i = 0;
	res = NULL;
	if (max <= min)
		return (NULL);
	len = max - min;
	if (!(res = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	return (res);
}
