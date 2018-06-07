/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:54:47 by cwu               #+#    #+#             */
/*   Updated: 2018/04/17 21:54:54 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;
	t_list *u;

	t = *alst;
	while (t)
	{
		u = t->next;
		del(t->content, t->content_size);
		free(t);
		t = u;
	}
	*alst = NULL;
}
