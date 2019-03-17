/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:53:06 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/16 19:17:39 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void		also_locking(t_info, t_path *path, int i)
{
	t_lock	*lock;
	t_path	*tmp;
}*/

void		locking(t_info *info, t_path *path, int i)
{
	t_lock	*lock;
	t_path	*tmp;
	int		ret;

	ret = 0;
	lock = path->locked;
	path->clength = info->total_length;
	while (lock)
	{
		lock->path->test = i;
		path->clength -= lock->path->room_col;
		lock = lock->next;
		ret++;
	}
	tmp = info->start_path;
	while (tmp)
	{
		if (tmp->test != i)
		{
			lock = tmp->locked;
			while (lock)
			{
				if (lock->path->test != i)
				{
					path->clength -= lock->path->room_col;
					lock->path->test = i;
					ret++;
				}
				lock = lock->next;
			}
		}
		tmp = tmp->prev;
	}
	path->sum_compatible = info->col_path - ret;
	path->clength /= path->sum_compatible;
	path->clength = info->ants / path->clength;
}

void		lock(t_path *path, t_path *start_path)
{
	t_lock	*lock;
	t_path	*tmp;

	lock = path->locked;
	while (lock)
	{
		lock->path->valid = 0;
		lock = lock->next;
	}
	tmp = start_path;
	while (tmp)
	{
		if (tmp->valid)
		{
			lock = tmp->locked;
			while (lock)
			{
				lock->path->valid = 0;
				lock = lock->next;
			}
		}
		tmp = tmp->prev;
	}
}

t_path		*best_var(t_info *info)
{
	int		best_compatible;
	int		best_clength;
	t_path	*tmp;
	t_path	*thebestway;
	
	tmp = info->start_path;
	best_compatible = -1;
	best_clength = 100000;
	while (tmp)
	{
		if (tmp->sum_compatible > best_compatible && tmp->clength < best_clength)
		{
			best_compatible = tmp->sum_compatible;
			thebestway = tmp;
		}
		tmp = tmp->prev;
	}
	return (thebestway);
}

void		sort_path(t_info *info)
{
	int		i;
	t_path	*tmp;

	i = 1;
	tmp = info->start_path;
	while (tmp)
	{
		locking(info, tmp, i++);
		tmp = tmp->prev;
	}
	lock(best_var(info), info->start_path);
}
