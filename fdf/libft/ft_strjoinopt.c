/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinopt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:12:21 by madecreu          #+#    #+#             */
/*   Updated: 2018/04/12 17:12:32 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinopt(char *s1, char *s2)
{
	char *tmp1;
	char *tmp2;

	tmp1 = s1;
	tmp2 = s2;
	s1 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	return (s1);
}
