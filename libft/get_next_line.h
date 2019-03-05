/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <akorobov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:00:15 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/03 17:56:03 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 1057
# include <unistd.h>
# include <stdlib.h>
# define TEST(x,y,z) if (x < 0 || x > 10240 || !y || !z) return (-1)
# define READ(x) if (x < 0) return (-1)
# define RET(x) (x == NULL) ? 0 : 1
# define TMP_NEW(x) if (!x)  x = ft_strnew(1)
# define JOIN(x, y) x = '\0'; y;

int	get_next_line(const int fd, char **line);

#endif
