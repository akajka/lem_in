/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:41:12 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/15 15:09:26 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				debug_mode(t_info *info, int mode)
{
	int				place;
	int				count;
	const char		*mods[4] = {"DEBUG",
	"INFO ABOUT THE ROOMS", "QUEUE", "PATHS"};

	count = 0;
	if (mode)
		printf("\n\n");
	place = (info->max.ts_cols + ft_strlen(mods[mode])) / 2;
	printf("\033[1;34m%*s\n\n\n\033[0m", place, mods[mode]);
}

void				print_name_room(char *name_room, int win, int description)
{
	if (description == 0)
		printf("\n\033[1;35m%*s%*s%*s\033[0m\n", win / 4 + 10,
				"name room", win / 2 - win / 4 - 8, "---",
				win / 4 - 7, name_room);
	else if (description == -1)
		printf("\033[1;34m%*s%*s%*s\033[0m\n", win / 4 + 20,
				"next room link name", win / 2 - win / 4 - 18, "---",
				win / 4 - 7, name_room);
	else if (description == 1)
		printf("\033[1;34m%*s%*s%*s\033[0m\n", win / 4 + 14,
				"elem in queue", win / 2 - win / 4 - 12, "---",
				win / 4 - 7, name_room);
	else if (description == 2)
		printf("\033[1;34m%*s%*s%*s\033[0m\n", win / 4 + 13,
				"elem in path", win / 2 - win / 4 - 11, "---",
				win / 4 - 7, name_room);
	else if (description == 4)
		printf("\033[1;31m%*s%*s%*s\033[0m\n", win / 4 + 10,
				"prev link", win / 2 - win / 4 - 8, "---",
				win / 4 - 7, name_room);
	else if (description == 5)
		printf("\033[1;31m%*s%s\033[0m\n", win / 4 + 13,
				"used by id_", name_room);
	else if (description == -2)
		printf("\033[1;35m%*s\033[0m\n", win / 4 + 6,
				"PATH:");
}

void				debug_print_queue(t_info *info)
{
	t_queue			*l;

	l = info->queue;
	debug_mode(info, DEBUG_QUEUE_MODE);
	while (l)
	{
		print_name_room(l->link->room->name_room, info->max.ts_cols, 1);
		if (l->link->prev)
			print_name_room(l->link->prev->room->name_room, info->max.ts_cols, 4);
		else
			print_name_room("missing", info->max.ts_cols, 4);
		l = l->next;
	}
	printf("\n\n");
	sleep(1);
}

void				debug_info_room(t_info *info)
{
	t_room			*tmp;
	t_link			*link;
	t_lock			*lockroom;

	tmp = info->room;
	debug_mode(info, DEBUG_INFO_MODE);
	printf("\n\033[1;34m%*s%*i\033[0m\n",
			info->max.ts_cols / 4 + 19,
			"Amount of rooms = ", 2, info->col_room - 1);
	printf("\033[1;35m%*s %d\033[0m\n", info->max.ts_cols / 4 + 47,
			"The sum of references to the starting point = ", info->sum_start_link);
	DEBUG == 2 ? sleep(2) : 0;
	while (tmp)
	{
		lockroom = tmp->locked;
		link = tmp->links;
		print_name_room(tmp->name_room, info->max.ts_cols, 0);
		printf("\033[35m%*s %d\033[0m\n", info->max.ts_cols / 4 + 10,
				"col links", tmp->p);
		if (link)
			while (link)
			{
				print_name_room(link->room->name_room, info->max.ts_cols, -1);
				link = link->next;
			}
		else
			print_name_room("missing", info->max.ts_cols, -1);
		if (lockroom)
			while (lockroom)
			{
				print_name_room(ft_itoa(lockroom->path->id), info->max.ts_cols, 5);
				lockroom = lockroom->next;
			}
		else
			print_name_room("missing", info->max.ts_cols, -1);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void				debug_print_path(t_info *info)
{
	t_path			*path;
	t_link			*link;
	t_lock			*lockroom;

	debug_mode(info, DEBUG_PATHS_MODE);
	path = info->paths;
	while (path)
	{
		if (path->valid)
		{
		print_name_room(NULL, info->max.ts_cols, -2);
		printf("\033[1;35m%*s %d\033[0m\n", info->max.ts_cols / 4 + 8,
				"Lenght:", path->room_col);
		printf("\033[1;31m%*s%d\033[0m\n", info->max.ts_cols / 4 + 5,
				"id_", path->id);

		lockroom = path->locked;
		link = path->link;
		while (link)
		{
			print_name_room(link->room->name_room, info->max.ts_cols, 2);
			link = link->next;
		}
		while (lockroom)
		{
			printf("\033[1;31m%*s%d\033[0m\n", info->max.ts_cols / 4 + 13,
				"conflict id_", lockroom->path->id);
			lockroom = lockroom->next;
		}
		printf("\n");
		}
		path = path->next;
	}
	printf("\n");
}
