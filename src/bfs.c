/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:28:47 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/14 21:56:36 by akorobov         ###   ########.fr       */
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
	if (!(new_el = (t_link *)ft_memalloc(sizeof(t_link))))
		print_error(ERROR_ALLOC_MEMORY, info->string);
	new_el->room = tmp->room;
	new_el->room->prev = info->queue->room;
	new_el->next = NULL;
	new_el->prev = last;
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

	while (info->queue)
	{
		info->queue->room->checked = 1;
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

t_path		*new_path_cr(t_info *info)
{
	t_link	*new_link;
	t_path	*new_path;

	new_path = (t_path *)ft_memalloc(sizeof(t_path));
	new_path->valid = 1;
	new_path->next = info->paths;
	new_link = (t_link *)ft_memalloc(sizeof(t_link));
	new_link->room = info->end;
	new_path->link = new_link;
	return (new_path);
}

void		new_way(t_link *last, t_info *info)
{
	t_path	*new_path;
	t_link	*new_link;
	t_room	*tmp_room;

	info->col_path++;
	new_path = new_path_cr(info);
	tmp_room = last->room;
	while (tmp_room != info->start && ++new_path->room_col)
	{
		new_link = (t_link *)ft_memalloc(sizeof(t_link));
		new_link->room = tmp_room;
		new_link->next = new_path->link;
		new_path->link->prev = new_link;
		new_path->link = new_link;
		introduction_room(tmp_room, new_path);
		tmp_room = tmp_room->prev;
	}
	info->paths ? info->paths->prev = new_path : 0;
	info->paths = new_path;
	DEBUG == 2 ? debug_print_path(info) : 0;
	DEBUG == 2 ? sleep(10) : 0;
}
