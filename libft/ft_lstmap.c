/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:57:22 by cwu               #+#    #+#             */
/*   Updated: 2018/04/17 21:57:23 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *t;

	if (!lst)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	t = new;
	while (lst->next)
	{
		t->next = f(lst->next);
		lst = lst->next;
		t = t->next;
	}
	return (new);
}
