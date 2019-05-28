/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:16:09 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/15 14:17:59 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_div_mod(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}
