/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 09:43:57 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/09 12:39:40 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] > 'a')
		{
			if (!(str[i - 1] <= 'z' && str[i - 1] >= 'a'))
				if (!(str[i - 1] <= 'Z' && str[i - 1] >= 'A'))
					if (!(str[i - 1] <= '9' && str[i - 1] >= '0'))
						str[i] = str[i] - 32;
		}
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			if (((str[i - 1] >= '0') && (str[i - 1] <= '9'))
			|| ((str[i - 1] >= 'A') && (str[i - 1] <= 'Z'))
			|| ((str[i - 1] >= 'a') && (str[i - 1] <= 'z'))
			|| str[i - 1] == 39)
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
