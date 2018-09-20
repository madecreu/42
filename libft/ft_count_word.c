/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:07:55 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/14 23:10:01 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(const char *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}
