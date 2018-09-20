/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:50:58 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/18 23:54:36 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int				longueur_de_nb(long nb)
{
	int		longueur;
	long	vabs;

	if (nb == 0)
		return (1);
	longueur = 0;
	if (nb >= 0)
		vabs = nb;
	else
		vabs = -1 * nb;
	while (vabs != 0)
	{
		vabs = (vabs - (vabs % 10)) / 10;
		longueur++;
	}
	return (longueur);
}

void			ft_putnbr_positiv(int nb)
{
	long	compteur;
	long	 a[longueur_de_nb((long)nb)];
	long	vabs;

	compteur = 0;
	if (nb >= 0)
		vabs = (long)nb;
	else
		vabs = (long)nb * (-1);
	while (vabs != 0)
	{
		a[longueur_de_nb(nb) - compteur - 1] = vabs % 10;
		vabs = (vabs - (vabs % 10)) / 10;
		compteur++;
	}
	compteur = 0;
	while (compteur <= longueur_de_nb(nb) - 1)
	{
		ft_putchar(a[compteur] + 48);
		compteur++;
	}
}

void			ft_putnbr(int nb)
{
	long	nb_long;

	nb_long = (long)nb;
	if (nb == 0)
		ft_putchar('0');
	else if (nb > 0)
		ft_putnbr_positiv(nb);
	else
	{
		ft_putchar('-');
		ft_putnbr_positiv(nb);
	}
}

void			ft_show_param(t_stock_par p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (p.str[i] != '\0')
	{
		ft_putchar(p.str[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putnbr(p.size_param);
	ft_putchar('\n');
	i = 0;
	while (p.tab[i] != NULL)
	{
		while (p.tab[i][j] != '\0')
		{
			ft_putchar(p.tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void			ft_show_tab(struct s_stock_par *par)
{
	int i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_show_param(par[i]);
		i++;
	}
}
