/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:28:44 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/04 15:29:28 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		fin(long nosegfault, int negative)
{
	if (negative == 1)
		nosegfault = -nosegfault;
	return ((int)nosegfault);
}

int		continu(char *str, int i, int negative, long nosegfault)
{
	int tmp;
	int comp;

	tmp = i;
	comp = 0;
	while (47 < str[i] && str[i] < 58)
	{
		comp++;
		i++;
	}
	i = tmp;
	while (comp > 0)
	{
		nosegfault *= 10;
		nosegfault += (str[i] - 48);
		comp--;
		i++;
	}
	return (fin(nosegfault, negative));
}

long	generelong(void)
{
	long nosegfault;

	nosegfault = 0;
	return (nosegfault);
}

int		ft_atoi(char *str)
{
	int i;
	int negative;

	i = 0;
	negative = 0;
	while (0 < str[i] && str[i] < 33)
		i++;
	if (str[i] == 45)
	{
		negative = 1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	if (!(47 < str[i] && str[i] < 58))
		return (0);
	return (continu(str, i, negative, generelong()));
}
