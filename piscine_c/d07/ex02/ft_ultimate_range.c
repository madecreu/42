/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:56:26 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/16 10:59:10 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*res;
	int		valmin;

	valmin = min;
	i = 0;
	res = NULL;
	if (max <= min)
		return (0);
	if (!(res = (int*)malloc(sizeof(int) * (max - min))))
		return (0);
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	*range = res;
	return (max - valmin);
}
