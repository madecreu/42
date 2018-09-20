/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:58:39 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/07 09:58:46 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (i * i <= nb)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 2;
		}
		else
			i++;
	}
	return (nb);
}
