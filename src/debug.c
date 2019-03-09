/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:41:12 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/09 22:42:02 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				debug_mode(t_info *info, int mode)
{
	int				place;
	int				count;
	char			*mods[4] =
	{"DEBUG", "INFO ABOUT THE ROOMS", "QUEUE","PATHS"};

	count = 0;
	if (mode)
		printf("\n\n");
	place = (info->max.ts_cols + ft_strlen(mods[mode])) / 2;
	printf("\033[1;34m%*s\n\n\n\033[0m", place, mods[mode]);
}

void				print_name_room(char *name_room, int winsize, int description)
{
	if (description == 0)
		printf("\n\033[1;35m%*s%*s%*s\033[0m\n" , winsize / 4 + 10,
				"name room", winsize / 2 - winsize / 4 - 8, "---",
				winsize / 4 - 7, name_room);
	else if (description == -1)
		printf("\033[1;34m%*s%*s%*s\033[0m\n", winsize / 4 + 20,
				"next room link name", winsize / 2 - winsize / 4 - 18, "---",
				winsize / 4 - 7, name_room);
	else if (description == 1)
		printf("\033[1;34m%*s%*s%*s\033[0m\n", winsize / 4 + 14,
				"elem in queue", winsize / 2 - winsize / 4 - 12, "---",
				winsize / 4 - 7, name_room);
	else if (description == 2)
		printf("\033[1;34m%*s%*s%*s\033[0m\n", winsize / 4 + 13,
				"elem in path", winsize / 2 - winsize / 4 - 11, "---",
				winsize / 4 - 7, name_room);
	else if (description == -2)
		printf("\033[1;35m%*s\033[0m\n", winsize / 4 + 6,
				"PATH:");
}

void				print_queue(t_info *info)
{
	t_link 			*l;
    
	l = info->queue;
	debug_mode(info, DEBUG_QUEUE_MODE);
	while (l)
	{
		print_name_room(l->room->name_room, info->max.ts_cols, 1);
		printf("\033[1;34m%*s %d\033[0m\n", info->max.ts_cols / 4 + 9,
				"checked:", l->room->checked);
		l = l->next;
	}
	printf("\n\n");
}

void				debug_info_room(t_info *info)
{
	t_room			*tmp;
	t_link			*link;

	tmp = info->room;
	debug_mode(info, DEBUG_INFO_MODE);
	printf("\n\033[1;34m%*s%*i\033[0m\n" ,
			info->max.ts_cols / 4 + 19,
			"Amount of rooms = ", 2, info->col_room - 1);
	while (tmp)
	{
		link = tmp->links;
		print_name_room(tmp->name_room, info->max.ts_cols, 0);
		if (link)
			while (link)
			{
				print_name_room(link->room->name_room, info->max.ts_cols, -1);
				link = link->next;
			}
		else
			print_name_room("missing", info->max.ts_cols, -1);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void	debug_print_path(t_info *info)
{
	t_path	*path;
	t_link	*link;

	debug_mode(info, DEBUG_PATHS_MODE);
	path = info->paths;
	while (path)
	{
		if (path->valid)
		{
			print_name_room(NULL, info->max.ts_cols, -2);
			printf("\033[1;35m%*s %d\033[0m\n", info->max.ts_cols / 4 + 8,
					"Lenght:", path->room_col);
			link = path->link;
			while (link)
			{
				print_name_room(link->room->name_room, info->max.ts_cols, 2);
				link = link->next;
			}
			printf("\n");
		}
		path = path->next;
	}
}
