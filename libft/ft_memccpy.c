/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:26:47 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 14:27:42 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	unsigned char *t;
	unsigned char *t2;

	t = (unsigned char *)dst;
	t2 = (unsigned char *)src;
	while (n--)
	{
		*t = *t2;
		t++;
		if (*t2 == (unsigned char)c)
			return (t);
		t2++;
	}
	return (NULL);
}
