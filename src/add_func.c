/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:48:13 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/09 21:44:55 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*new_room(t_info *info, char **line)
{
	t_room	*tmp;

	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->next = info->room;
	tmp->name_room = ft_strdup(line[0]);
	tmp->y = ft_atoi(line[1]);
	tmp->x = ft_atoi(line[2]);
	tmp->links = NULL;
	return (tmp);
}

void		get_extremity(t_info *info)
{
	char	**split;
	char	c;
	int		count;

	count = 0;
	c = info->line->content[2];
	info->line = info->line->next;
	if (info->line && ++info->string)
	{
		split = ft_strsplit(info->line->content, ' ');
		if (ft_size2d(split) != 3)
			print_error(c, info->string);
		info_room(info, split);
		if (c == 's')
			info->start = info->room;
		else
			info->end = info->room;
		free_2d(&split);
	}
	else
		print_error(c, info->string);
}

void		val_test_room(t_room *rooms, t_room *tmp, int string)
{
	t_room	*test;

	test = rooms;
	while (test && test->name_room)
	{
		if (!ft_strcmp(test->name_room, tmp->name_room))
			print_error('d', string);
		if (test->x == tmp->x && test->y == tmp->y)
			print_error('Z', string);
		test = test->next;
	}
}

void		val_test_link(t_room *room_link, t_room *need_room, int string)
{
	t_link	*nd;
	t_link	*rl;

	nd = need_room->links;
	rl = room_link->links;
	while (nd)
	{
		if (nd->room == room_link)
			print_error('l', string);
		nd = nd->next;
	}
	while (rl)
	{
		if (rl->room == need_room)
			print_error('l', string);
		rl = rl->next;
	}
}

void		new_link(t_room *rooms, t_room *need_room,
		char *name_link, int string)
{
	t_room	*room_link;
	t_link	*new_link;

	if (!ft_strcmp(need_room->name_room, name_link))
		print_error('l', string);
	room_link = rooms;
	while (room_link)
		if (ft_strcmp(room_link->name_room, name_link))
			room_link = room_link->next;
		else
			break ;
	if (room_link)
	{
		val_test_link(room_link, need_room, string);
		new_link = (t_link *)malloc(sizeof(t_link));
		new_link->room = room_link;
		new_link->next = need_room->links;
		need_room->links = new_link;
	}
	else
		print_error('l', string);
}
