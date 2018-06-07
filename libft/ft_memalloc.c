/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:48:20 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 20:48:22 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *t;
	unsigned char *u;

	t = (unsigned char*)malloc(size);
	if (!t)
		return (NULL);
	u = t;
	while (size--)
		*u++ = 0;
	return ((void*)t);
}
