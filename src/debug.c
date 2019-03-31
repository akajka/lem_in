/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:41:12 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/17 18:11:10 by akorobov         ###   ########.fr       */
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

void				debug_print_queue(t_queue *queue, t_info *info)
{
	t_queue			*l;

	l = queue;
	debug_mode(info, DEBUG_QUEUE_MODE);
	while (l)
	{
		print_elem_str(l->link->room->name_room,
				info->max.ts_cols, DEBUG_QUEUE_ITEM);
		if (l->link->prev)
			print_elem_str(l->link->prev->room->name_room,
					info->max.ts_cols, DEBUG_PREVIOS_ROOM);
		else
			print_elem_str("missing",
					info->max.ts_cols, DEBUG_PREVIOS_ROOM);
		l = l->next;
	}
	printf("\n\n");
}

void				debug_info_room(t_info *info)
{
	t_room			*tmp;

	tmp = info->room;
	debug_mode(info, DEBUG_INFO_MODE);
	print_elem_nbr(info->col_room,
			info->max.ts_cols, DEBUG_NUMBER_OF_ROOMS);
	print_elem_nbr(info->sum_start_link,
			info->max.ts_cols, DEBUG_LINKS_START);
	while (tmp)
	{
		print_elem_str(tmp->name_room, info->max.ts_cols, DEBUG_NAME_ROOM);
		print_elem_nbr(tmp->p, info->max.ts_cols, DEBUG_NUMBER_OF_LINKS);
		print_links(info, tmp->links);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void				debug_print_path(t_info *info)
{
	t_path			*path;

	debug_mode(info, DEBUG_PATHS_MODE);
	path = info->paths;
	while (path)
	{
		print_elem_str("", info->max.ts_cols, DEBUG_PATH);
		print_elem_nbr(path->id, info->max.ts_cols, DEBUG_ID);
		print_elem_nbr(path->room_col, info->max.ts_cols, DEBUG_LENGTH);
		print_links(info, path->link);
		path = path->next;
	}
	printf("\n");
}
