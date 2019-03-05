/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <akorobov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:13 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/04 17:49:36 by akorobov         ###   ########.fr       */
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
	while ((ret = read(fd, &buf, 1)))
	{
		if (buf == '\n')
		{
			tmp[count++] = '\0';
			if (tmp[0] != '\0')
				*line = ft_strdup(tmp);
			return (*line ? 1 : 0);
		}
		else
			tmp[count++] = buf;
	}
	return (0);
}
