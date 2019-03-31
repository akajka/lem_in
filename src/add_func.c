/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:48:13 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/18 15:05:14 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*new_room(t_info *info, char **line)
{
	t_room	*tmp;

	if (!(tmp = (t_room *)ft_memalloc(sizeof(t_room))))
		print_error(ERROR_ALLOC_MEMORY, info->string);
	tmp->next = info->room;
	if (!(tmp->name_room = ft_strdup(line[0])))
		print_error(ERROR_ALLOC_MEMORY, info->string);
	tmp->y = ft_atoi(line[1]);
	tmp->x = ft_atoi(line[2]);
	tmp->links = NULL;
	return (tmp);
}

void		get_extremity(t_info *info)
{
	char	**split;
	int		er;
	int		count;

	count = 0;
	er = (info->line->content[2] == 's' ? ERROR_START_INIT :
			ERROR_END_INIT);
	info->line = info->line->next;
	if (info->line && ++info->string)
	{
		while (info->line->content && (info->line->content[0] == '#' &&
					info->line->content[1] != '#') && ++info->string)
			info->line = info->line->next;
		split = ft_strsplit(info->line->content, ' ');
		if (ft_size2d(split) != 3 || (!er ? info->start : info->end))
			print_error(er, info->string);
		info_room(info, split);
		if (er == ERROR_START_INIT)
			info->start = info->room;
		else
			info->end = info->room;
		free_2d(&split);
	}
	else
		print_error(er, info->string);
}

void		val_test_room(t_room *rooms, t_room *tmp, int string)
{
	t_room	*test;

	test = rooms;
	while (test && test->name_room)
	{
		if (!ft_strcmp(test->name_room, tmp->name_room))
			print_error(ERROR_REPEAT_ROOM, string);
		if (test->x == tmp->x && test->y == tmp->y)
			print_error(ERROR_REPEAT_COOR, string);
		test = test->next;
	}
}

void		val_test_link(t_room *room_link, t_room *need_room, int string)
{
	t_link	*nd;

	nd = need_room->links;
	while (nd)
	{
		if (nd->room == room_link)
			print_error(ERROR_VALID_LINK, string);
		nd = nd->next;
	}
}

void		new_link(t_room *rooms, t_room *need_room,
		char *name_link, int string)
{
	t_room	*room_link;
	t_link	*new_link;

	if (!ft_strcmp(need_room->name_room, name_link))
		print_error(ERROR_VALID_LINK, string);
	room_link = rooms;
	while (room_link)
		if (ft_strcmp(room_link->name_room, name_link))
			room_link = room_link->next;
		else
			break ;
	if (room_link)
	{
		if (!(new_link = (t_link *)ft_memalloc(sizeof(t_link))))
			print_error(ERROR_ALLOC_MEMORY, string);
		new_link->room = room_link;
		new_link->next = need_room->links;
		if (need_room->links)
			need_room->links->prev = new_link;
		need_room->links = new_link;
	}
	else
		print_error(ERROR_VALID_LINK, string);
}
