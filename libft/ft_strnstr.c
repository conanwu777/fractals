/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:28:33 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 16:30:35 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	int		i;

	h = (char*)haystack;
	if (*needle == '\0')
		return (h);
	while (*h)
	{
		i = 0;
		while (needle[i] && *(h + i) == needle[i] && h + i < haystack + len)
			i++;
		if (needle[i] == '\0')
			return (h);
		h++;
	}
	return ((void*)0);
}
