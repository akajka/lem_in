/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:28:47 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/11 14:09:25 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		pushback_queue(t_info *info, t_link *tmp)
{
	t_link	*new_el;
	t_link	*last;

	last = info->queue;
	while (last->next)
		last = last->next;
	new_el = (t_link *)malloc(sizeof(t_link));
	new_el->room = tmp->room;
	new_el->room->prev = info->queue->room;
	new_el->next = NULL;
	last->next = new_el;
}

int			val_test_elem_queue(t_room *room, t_link *queue)
{
	t_link	*tmp;

	tmp = queue;
	while (tmp)
	{
		if (tmp->room == room)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_link		*bfs(t_info *info)
{
	t_link	*tmp;

	info->us++;
	while (info->queue)
	{
		info->queue->room->checked = info->us;
		g_g ? print_queue(info) : 0;
		tmp = info->queue->room->links;
		while (tmp)
		{
			if (!tmp->room->checked)
			{
				if (tmp->room == info->end)
					return (info->queue);
				if (val_test_elem_queue(tmp->room, info->queue))
					pushback_queue(info, tmp);
			}
			tmp = tmp->next;
		}
		info->queue = info->queue->next;
	}
	return (NULL);
}

void		new_way(t_link *last, t_info *info)
{
	t_path	*new_path;
	t_link	*new_link;
	t_room	*tmp_room;

	new_path = (t_path *)ft_memalloc(sizeof(t_path));
	new_path->next = info->paths;
	tmp_room = last->room;
	while (tmp_room != info->start && ++new_path->room_col &&
			tmp_room->checked == info->us)
	{
		new_link = (t_link *)ft_memalloc(sizeof(t_link));
		new_link->room = tmp_room;
		new_link->next = new_path->link;
		if (new_path->link)
			new_path->link->prev = new_link;
		new_path->link = new_link;
		tmp_room = tmp_room->prev;
	}
	if (tmp_room == info->start && ++info->col_path)
		new_path->valid = 1;
	if (info->paths)
		info->paths->prev = new_path;
	info->paths = new_path;
	g_g ? debug_print_path(info) : 0;
}
