/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:29:04 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 14:29:15 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int m;

	while (n--)
	{
		m = *(const unsigned char *)s1++ - *(const unsigned char *)s2++;
		if (m != 0)
			return (m);
	}
	return (0);
}
