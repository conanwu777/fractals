/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:28:01 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 14:28:10 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *t;
	unsigned char *t2;

	t = (unsigned char *)dst;
	t2 = (unsigned char *)src;
	if (t2 < t)
		while (len--)
			t[len] = t2[len];
	else
		while (len--)
			*t++ = *t2++;
	return (dst);
}
