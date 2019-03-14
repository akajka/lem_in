/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:57:50 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/14 22:02:21 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		if (path->valid)
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
		if (path->valid)
		{
			while (++j != i)
				path->ness += len[i] - len[j];
			i++;
		}
		path = path->prev;
	}
	free(len);
}

void		add_lock(t_path *first, t_path *second)
{
	t_lock	*lock;

	first->sum_not_compatible++;
	lock = (t_lock *)ft_memalloc(sizeof(t_lock));
	lock->path = second;
	lock->next = first->locked;
	first->locked = lock;
	second->sum_not_compatible++;
	lock = (t_lock *)ft_memalloc(sizeof(t_lock));
	lock->path = first;
	lock->next = second->locked;
	second->locked = lock;
}

void		ban(t_room *room, t_path *path)
{
	t_lock	*lpath;
	t_lock	*l_not_val_path;

	lpath = room->locked;
	l_not_val_path = path->locked;
	while (lpath)
	{
		while (l_not_val_path)
		{
			if (l_not_val_path->path == lpath->path)
				break ;
			l_not_val_path = l_not_val_path->next;
		}
		l_not_val_path = path->locked;
		if (!l_not_val_path)
			add_lock(path, lpath->path);
		lpath = lpath->next;
	}
}

void		introduction_room(t_room *cur_room, t_path *cur_path)
{
	t_lock	*lpath;

	ban(cur_room, cur_path);
	lpath = (t_lock *)ft_memalloc(sizeof(t_lock));
	lpath->path = cur_path;
	lpath->next = cur_room->locked;
	cur_room->locked = lpath;
}
