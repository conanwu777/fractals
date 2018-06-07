/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 00:56:18 by cwu               #+#    #+#             */
/*   Updated: 2018/03/20 00:59:01 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	unsigned long	i;
	int				l;

	l = 0;
	while (s1[l])
		l++;
	i = -1;
	while (++i < n && s2[i])
		s1[l + i] = s2[i];
	s1[l + i] = '\0';
	return (s1);
}
