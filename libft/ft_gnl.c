/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:46:17 by cwu               #+#    #+#             */
/*   Updated: 2018/04/18 19:46:19 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cw_stradd_chop(char *line, char *toadd, int size, int i)
{
	char	*l;

	if (!line || !(*line))
	{
		if ((line = ft_strnew(size + 1)))
			line = ft_strncpy(line, toadd, size + 1);
		return (line);
	}
	l = line;
	if (!(line = ft_strnew(ft_strlen(line) + i * size + 1)))
		return (NULL);
	if (i == 1)
	{
		line = ft_strcpy(line, l);
		line = ft_strncat(line, toadd, size + 1);
	}
	else
		line = ft_strcpy(line, l + size);
	ft_strdel(&l);
	return (line);
}

static void	mem_to_line(char **line, char **mem, char *str, int *r)
{
	int		e;

	if (!(*mem))
		*line = NULL;
	else
	{
		*r = 1;
		if (!ft_strstr(*mem, str))
		{
			*line = *mem;
			*mem = NULL;
		}
		else
		{
			e = ft_strstr(*mem, str) - *mem;
			*line = ft_strnew(e + 1);
			*line = ft_strncpy(*line, *mem, e);
			if (*((*mem) + e) && *((*mem) + e + 1))
				*mem = cw_stradd_chop((*mem), NULL, e + ft_strlen(str), -1);
			else
				ft_strdel(mem);
		}
	}
}

int			get_next(const int fd, char **line, char *str)
{
	static t_file		mem[MAX_FILENUMBER + 1];
	char				buf[BUFF_SIZE + 1];
	int					r;

	if (read(fd, buf, 0))
	{
		if (fd >= 0 && fd < MAX_FILENUMBER && mem[fd].fd == fd + 1)
			mem[fd].fd = 0;
		return (-1);
	}
	if (mem[fd].fd != fd + 1)
		mem[fd].m = NULL;
	mem[fd].fd = fd + 1;
	r = 0;
	if (!(mem[fd].m) || !ft_strstr(mem[fd].m, str))
		while ((r = read(fd, buf, BUFF_SIZE)))
		{
			buf[r] = '\0';
			if (!(mem[fd].m = cw_stradd_chop(mem[fd].m, buf, BUFF_SIZE, 1)))
				return (-1);
			if (ft_strstr(mem[fd].m, str))
				break ;
		}
	mem_to_line(line, &(mem[fd].m), str, &r);
	return ((*line && r != 0) ? 1 : 0);
}

int			ft_gnl(const int fd, char **line)
{
	return (get_next(fd, line, "\n"));
}
