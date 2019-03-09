/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go_to_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:39:26 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/09 22:57:06 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_go_to_the_next_room_in_this_way(t_path *path, t_info *info)
{
	t_link	link;

	link = path->link;
	while (link->room->ant)
		link = link->next;
	
}

void	ants_go_to_end(t_info *info)
{
	t_path	path;

	while (info->ants)
	{
		path = info->start_path;
		while (path)
		{
			if (path->valid)
				ant_go_to_the_next_room_in_this_way(path, info);
			path = path->prev;
		}
	}
}
