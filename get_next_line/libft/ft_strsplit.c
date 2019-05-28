/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:32:54 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/12 15:50:00 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(const char *s, char c)
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

static int		count_letter(const char *s, char c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		words;
	int		n;

	if (!s)
		return (NULL);
	n = 0;
	words = count_word((const char *)s, c);
	if (!(res = (char**)malloc(sizeof(*res) *
					(count_word((const char *)s, c) + 1))))
		return (NULL);
	while (words--)
	{
		while (*s == c && *s)
			s++;
		res[n] = ft_strsub(s, 0, count_letter((const char *)s, c));
		if (res[n] == NULL)
			return (NULL);
		s += count_letter((const char *)s, c);
		n++;
	}
	res[n] = NULL;
	return (res);
}
