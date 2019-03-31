/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:57:50 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/17 18:17:59 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*init_queue(t_info *info)
{
	t_queue	*queue;

	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	queue->link = (t_link *)ft_memalloc(sizeof(t_link));
	queue->link->room = info->start;
	return (queue);
}

int			*init_len(t_info *info)
{
	int		*ret;
	int		count;
	t_path	*path;

	count = 0;
	ret = (int *)malloc(sizeof(int) * info->col_path);
	path = info->start_path;
	while (path)
	{
		ret[count++] = path->room_col;
		path = path->prev;
	}
	return (ret);
}

void		ness_use_path(t_info *info)
{
	int		i;
	int		j;
	int		*len;
	t_path	*path;

	info->ant_during_way = (t_way *)ft_memalloc(sizeof(t_way) * info->ants);
	len = init_len(info);
	path = info->start_path;
	i = 0;
	while (path)
	{
		j = -1;
		while (++j != i)
			path->ness += len[i] - len[j];
		i++;
		path = path->prev;
	}
	free(len);
}
