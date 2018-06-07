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

char	*cw_strchop(char *line, int size)
{
	char	*tmp;
	char	*l;
	int		i;

	if (!line || !(*line))
		return ((char*)malloc(1));
	tmp = ft_strnew(ft_strlen(line) - size + 1);
	l = line;
	line = tmp;
	i = -1;
	while (l[++i + size])
		line[i] = l[i + size];
	ft_strdel(&l);
	return (line);
}
