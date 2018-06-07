/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 00:54:29 by cwu               #+#    #+#             */
/*   Updated: 2018/03/20 01:51:51 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	l;
	unsigned int	i;

	l = 0;
	while (dst[l])
		l++;
	i = -1;
	while (++i + l + 1 < dstsize && src[i] != '\0')
		dst[l + i] = src[i];
	dst[l + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	return ((l < dstsize) ? l + i : dstsize + i);
}
