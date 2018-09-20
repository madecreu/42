/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:41:50 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/05 19:12:56 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		if (tab[i - 1] <= tab[i])
			i++;
		else
		{
			temp = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = temp;
			i = 0;
			i++;
		}
	}
}
