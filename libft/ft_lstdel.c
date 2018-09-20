/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:32:53 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/13 12:48:45 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *newl;

	while (*alst)
	{
		newl = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = newl;
	}
	*alst = NULL;
}
