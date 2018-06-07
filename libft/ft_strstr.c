/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:28:33 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 16:30:15 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	int		i;

	h = (char*)haystack;
	if (*needle == '\0')
		return (h);
	while (*h)
	{
		i = 0;
		n = (char*)needle;
		while (*n && *(h + i++) == *n)
			n++;
		if (!*n)
			return (h);
		h++;
	}
	return (NULL);
}
