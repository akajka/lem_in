/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <akorobov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:13 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/27 09:34:44 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

int				get_next_line(const int fd, char **line)
{
	int			ret;
	int			count;
	char		buf;
	char		tmp[2048];

	*line = NULL;
	count = 0;
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		if (buf == '\n')
		{
			tmp[count++] = '\0';
			*line = (char *)ft_memalloc(sizeof(char) * (count + 1));
			ft_strcpy(*line, tmp);
			return (*line ? 1 : 0);
		}
		tmp[count++] = buf;
	}
	if (count != 0)
	{
		tmp[count++] = '\0';
		*line = (char *)ft_memalloc(sizeof(char) * (count + 1));
		ft_strcpy(*line, tmp);
	}
	return (*line ? 1 : 0);
}
