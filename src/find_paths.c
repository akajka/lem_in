/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:28:47 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/05 15:45:54 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		find_path(t_info *info)
{
	info->path->link->room = info->start;
	while (info->path->link->room->links)
	{
		bfs(info->path);
		info->path->link->room->links = info->path->link->room->links->next; 
	}
}
