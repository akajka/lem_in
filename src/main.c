/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:37 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 21:58:01 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_extremity(t_info *info)
{
	if (!info->start || !info->start->links)
		print_error(ERROR_START_INIT, info->string);
	if (!info->end)
		print_error(ERROR_END_INIT, info->string);
}

void		debug(t_info *info)
{
	if (ioctl(1, TIOCGWINSZ , &info->max) == -1)
		printf("ERROR in ioctl");
	debug_mode(info, DEBUG_START_MODE);
	debug_info_room(info);
}

int			main()
{
	t_link	*link_to_end;
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	get_info(info);
	check_extremity(info);
	DEBUG ? debug(info) : 0;
	info->queue = (t_link *)ft_memalloc(sizeof(t_link));
	info->queue->room = info->start;
	info->q = info->queue;
	while ((link_to_end = bfs(info)))
	{
		new_way(link_to_end, info);
		if (!info->start_path)
			info->start_path = info->paths;
		if (!(info->queue = info->queue->next))
			break ;
	}
	DEBUG ? debug_print_path(info) : 0;
	info->paths ? ants_go(info) : print_error(ERROR_PATH_NOT_FOUND,
			info->string);
	return (0);
}
