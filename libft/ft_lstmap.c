/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:50:51 by madecreu          #+#    #+#             */
/*   Updated: 2017/11/13 16:33:00 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*move;
	t_list	*nest;
	t_list	*itwalking;

	if (lst == NULL)
		return (NULL);
	nest = f(lst);
	itwalking = lst->next;
	move = nest;
	while (itwalking)
	{
		move->next = f(itwalking);
		move = move->next;
		itwalking = itwalking->next;
	}
	return (nest);
}
