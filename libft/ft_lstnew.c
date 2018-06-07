/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:53:09 by cwu               #+#    #+#             */
/*   Updated: 2018/04/17 21:53:09 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *t;

	if (!(t = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		t->content = NULL;
		t->content_size = 0;
		t->next = NULL;
		return (t);
	}
	if (!(t->content = (void*)malloc(content_size)))
		return (NULL);
	ft_memcpy(t->content, content, content_size);
	t->content_size = content_size;
	t->next = NULL;
	return (t);
}
