/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:05:45 by madecreu          #+#    #+#             */
/*   Updated: 2017/08/18 10:57:28 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strcat(char *dest, char *src, int lastword)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (dest[i] != '\0')
		i++;
	while (src[n] != '\0')
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	if (lastword == 0)
		dest[i] = '\n';
	else
		dest[i] = '\0';
	return (dest);
}

int		camecasselescouilles(char **argv)
{
	int i;
	int	malloc_size;

	i = 1;
	malloc_size = 0;
	while (argv[i] != '\0')
	{
		malloc_size += ft_strlen(argv[i]);
		i++;
	}
	return (malloc_size);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		malloc_size;
	char	*res;

	if (argc <= 1)
		return (ft_strdup("\0"));
	i = -1;
	malloc_size = camecasselescouilles(argv);
	if ((!(res = (char *)malloc(sizeof(char) * (malloc_size + 1)))))
		return (NULL);
	while (++i < malloc_size + 1)
		res[i] = '\0';
	i = 1;
	while (i < argc - 1)
	{
		res = ft_strcat(res, argv[i], 0);
		i++;
	}
	res = ft_strcat(res, argv[i], 1);
	return (res);
}
