/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:28:47 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/18 12:36:45 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_queue(t_path *path, t_queue *queue)
{
	t_path	*tmp;
	t_queue	*next;

	tmp = path;
	next = queue->next;
	free(queue->link);
	free(queue);
	queue = next;
	while (queue)
	{
		next = queue->next;
		if (tmp && queue->link == tmp->link)
			tmp = tmp->next;
		else
			free(queue->link);
		free(queue);
		queue = next;
	}
}

void		pushback_queue(t_queue *queue, t_link *tmp)
{
	t_queue	*new_queue;
	t_queue	*last;
	t_link	*new_link;

	if (tmp->room->links && !tmp->room->used)
	{
		last = queue;
		while (last->next)
			last = last->next;
		new_queue = (t_queue *)ft_memalloc(sizeof(t_queue));
		new_link = (t_link *)ft_memalloc(sizeof(t_link));
		new_link->room = tmp->room;
		new_link->prev = queue->link;
		new_queue->link = new_link;
		new_queue->prev = last;
		last->next = new_queue;
	}
}

int			bfs(t_info *info)
{
	t_link	*tmp;
	t_queue	*del;
	t_queue	*queue;

	queue = init_queue(info);
	del = queue;
	while (queue && (queue->link->room->checked = info->us))
	{
		tmp = queue->link->room->links;
		DEBUG == 2 ? debug_print_queue(queue, info) : 0;
		while (tmp)
		{
			if (tmp->room == info->end)
			{
				new_way(queue->link, info, del);
				return (1);
			}
			if (tmp->room->checked != info->us)
				pushback_queue(queue, tmp);
			tmp = tmp->next;
		}
		queue = queue->next;
	}
	del_queue(info->paths, del);
	return (0);
}

t_path		*new_path_cr(t_info *info)
{
	t_link	*new_link;
	t_path	*new_path;

	new_path = (t_path *)ft_memalloc(sizeof(t_path));
	new_path->id = info->col_path;
	new_path->next = info->paths;
	new_link = (t_link *)ft_memalloc(sizeof(t_link));
	new_link->room = info->end;
	new_path->link = new_link;
	return (new_path);
}

void		new_way(t_link *last, t_info *info, t_queue *del)
{
	t_path	*new_path;
	t_link	*new_link;
	t_link	*tmp_link;

	info->col_path++;
	new_path = new_path_cr(info);
	info->start_path ? 0 : (info->start_path = new_path);
	tmp_link = last;
	while (tmp_link->room != info->start && ++new_path->room_col)
	{
		tmp_link->room->used = 1;
		new_link = (t_link *)ft_memalloc(sizeof(t_link));
		new_link->room = tmp_link->room;
		new_link->next = new_path->link;
		new_path->link->prev = new_link;
		new_path->link = new_link;
		tmp_link = tmp_link->prev;
	}
	info->paths ? info->paths->prev = new_path : 0;
	info->paths = new_path;
	DEBUG == 2 ? debug_print_path(info) : 0;
	DEBUG == 2 ? sleep(2) : 0;
	del_queue(info->paths, del);
}
