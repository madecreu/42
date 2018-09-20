/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:09:31 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/18 23:56:22 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

t_stock_par				ft_fill_one_param(char *av)
{
	t_stock_par		res;
	int				i;
	int				j;
	char			*cpy;

	i = 0;
	j = 0;
	while (av[i] != '\0')
		i++;
	res.size_param = i;
	res.str = av;
	cpy = (char*)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		cpy[j] = av[j];
		j++;
	}
	res.copy = cpy;
	res.tab = ft_split_whitespaces(av);
	return (res);
}

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*res;

	i = 0;
	res = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		res[i] = ft_fill_one_param(av[i]);
		i++;
	}
	res[i].str = NULL;
	return (res);
}
