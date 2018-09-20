/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:28:10 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/16 00:30:11 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_copy(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	while (str[i] != '\0')
		i++;
	cpy = (char*)malloc(sizeof(cpy) * i);
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_count_word(char *str, int tab[500])
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32 && str[i] != 127)
		{
			tab[word] = i;
			word++;
			while (str[i] > 32)
				i++;
			str[i] = '\0';
		}
		i++;
	}
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	int		i;
	int		nb_word;
	int		tab[500];
	char	*copy;

	i = 0;
	copy = ft_copy(str);
	nb_word = ft_count_word(copy, tab);
	if (!(res = (char**)malloc(sizeof(*res) * (nb_word))))
		return (NULL);
	while (nb_word != 0)
	{
		res[i] = &copy[tab[i]];
		nb_word--;
		i++;
	}
	res[i] = NULL;
	return (res);
}
