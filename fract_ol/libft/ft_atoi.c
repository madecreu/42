/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:09:33 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/12 15:43:28 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		returncompare(long long res)
{
	if (res > 9223372036854775807)
		return (-1);
	else
		return (0);
}

static int		comparebool(long long res)
{
	if (res > 9223372036854775807 || res < -9223372036854775807)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int				i;
	long long		res;
	int				neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (comparebool(res) == 1)
		return (returncompare(res * neg));
	return ((int)(res * neg));
}
