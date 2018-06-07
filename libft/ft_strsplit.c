/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:04:33 by cwu               #+#    #+#             */
/*   Updated: 2018/04/17 00:04:34 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	size_t	i;
	int		j;

	if (!s || !(r = (char**)malloc(sizeof(char*) * (cw_countw(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < cw_countw(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		r[j] = ft_strsub(s, i, cw_wordl(s, c, i));
		j++;
		i += cw_wordl(s, c, i);
	}
	r[j] = 0;
	return (r);
}
