/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:53:00 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/02 17:34:38 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print(int d1, int u1, int d2, int u2)
{
	if (d1 * 10 + u1 < d2 * 10 + u2)
	{
		ft_putchar(d1 + 48);
		ft_putchar(u1 + 48);
		ft_putchar(' ');
		ft_putchar(d2 + 48);
		ft_putchar(u2 + 48);
		if (d1 != 9 || u1 != 8 || d2 != 9 || u2 != 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	all_while(int d1, int u1, int d2, int u2)
{
	while (d1 < 10)
	{
		while (u1 < 10)
		{
			while (d2 < 10)
			{
				while (u2 < 10)
				{
					print(d1, u1, d2, u2);
					u2++;
				}
				u2 = 0;
				d2++;
			}
			d2 = 0;
			u1++;
		}
		u1 = 0;
		d1++;
	}
}

void	ft_print_comb2(void)
{
	int d1;
	int u1;
	int d2;
	int u2;

	d1 = 0;
	u1 = 0;
	d2 = 0;
	u2 = 0;
	all_while(d1, u1, d2, u2);
}
