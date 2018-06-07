/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:22:20 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 23:22:21 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *t;
	char *u;

	if (!s1 || !s2 || !(t = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	u = t;
	while (*s1)
		*u++ = *s1++;
	while (*s2)
		*u++ = *s2++;
	*u = '\0';
	return (t);
}
