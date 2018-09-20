/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:29:22 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/02 13:49:44 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print(int c, int d, int u)
{
	if (c < d && d < u)
	{
		ft_putchar(c + 48);
		ft_putchar(d + 48);
		ft_putchar(u + 48);
		if (c != 7 || d != 8 || u != 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb(void)
{
	int c;
	int d;
	int u;

	c = 0;
	d = 0;
	u = 0;
	while (c < 8)
	{
		while (d < 10)
		{
			while (u < 10)
			{
				print(c, d, u);
				u++;
			}
			u = 0;
			d++;
		}
		d = 0;
		c++;
	}
}
