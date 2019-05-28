/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:00:50 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/06 16:28:24 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int i;
	int c;

	i = 1;
	c = 0;
	if (ac < 2)
		return (0);
	while (av[i])
	{
		while (av[i][c])
		{
			ft_putchar(av[i][c]);
			c++;
		}
		ft_putchar('\n');
		c = 0;
		i++;
	}
	return (0);
}
