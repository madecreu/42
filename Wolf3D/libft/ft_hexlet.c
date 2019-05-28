/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:12:32 by khtran            #+#    #+#             */
/*   Updated: 2018/05/10 18:12:33 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_hexlet(int chiffre)
{
	char	*base;

	base = "0123456789ABCDEF";
	return (base[chiffre]);
}
