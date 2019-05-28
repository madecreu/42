/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:08:09 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/07 22:17:20 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*res;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	if (!(res = (int*)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
