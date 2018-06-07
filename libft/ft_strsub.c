/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:01:25 by cwu               #+#    #+#             */
/*   Updated: 2018/04/16 23:01:26 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	if (!(t = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (s && len--)
	{
		t[i] = s[start + i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
