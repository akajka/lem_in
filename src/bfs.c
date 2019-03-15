/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:28:47 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/15 22:41:11 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		pushback_queue(t_info *info, t_link *tmp)
{
	t_queue	*new_queue;
	t_queue	*last;
	t_link	*new_link;

	last = info->queue;
	while (last->next)
		last = last->next;
	if (!(new_queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		print_error(ERROR_ALLOC_MEMORY, info->string);
	if (!(new_link = (t_link *)ft_memalloc(sizeof(t_link))))
		print_error(ERROR_ALLOC_MEMORY, info->string);
	new_link->room = tmp->room;
	new_link->next = NULL;
	new_link->prev = info->queue->link;
	info->queue->link->next = new_link;
	new_queue->link = new_link;
	last->next = new_queue;
}

t_link		*bfs(t_info *info)
{
	t_link	*tmp;

	while (info->queue)
	{
		info->queue->link->room->checked = 1;
		tmp = info->queue->link->room->links;
		DEBUG == 2 ? debug_print_queue(info) : 0;
		while (tmp)
		{
			if (tmp->room == info->end)
				return (info->queue->link);
			if (!tmp->room->checked && tmp->room->links)
				pushback_queue(info, tmp);
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
	new_path->id = info->col_path;
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
	t_link	*tmp_link;

	info->col_path++;
	new_path = new_path_cr(info);
	tmp_link = last;
	while (tmp_link->room != info->start && ++new_path->room_col)
	{
		new_link = (t_link *)ft_memalloc(sizeof(t_link));
		new_link->room = tmp_link->room;
		new_link->next = new_path->link;
		new_path->link->prev = new_link;
		new_path->link = new_link;
		introduction_room(tmp_link->room, new_path);
		tmp_link = tmp_link->prev;
	}
	info->paths ? info->paths->prev = new_path : 0;
	info->paths = new_path;
	DEBUG == 2 ? debug_print_path(info) : 0;
	DEBUG == 2 ? sleep(10) : 0;
}
