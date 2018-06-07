/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:43:51 by cwu               #+#    #+#             */
/*   Updated: 2018/03/16 14:50:03 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cw_stradd(char *line, char *toadd, int size)
{
	char	*tmp;
	char	*l;
	int		i;

	if (!line || !(*line))
	{
		tmp = ft_strnew(size + 1);
		line = tmp;
		while (size--)
			*tmp++ = *toadd++;
		return (line);
	}
	tmp = ft_strnew(ft_strlen(line) + size + 1);
	l = line;
	line = tmp;
	i = -1;
	while (l[++i])
		*tmp++ = l[i];
	ft_strdel(&l);
	while (size--)
		*tmp++ = *toadd++;
	return (line);
}
