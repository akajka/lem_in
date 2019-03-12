/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:37 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 17:41:16 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_extremity(t_info *info)
{
	if (!info->start || !info->start->links)
		print_error('s', info->string + 1);
	if (!info->end)
		print_error('e', info->string + 1);
}

void		debug(int argc, char **argv, t_info *info)
{
	int		i;

	i = -1;
	if (argc >= 2)
		while (argv[++i])
		{
			if (!ft_strcmp(argv[i], "-g"))
				g_debug_mode = 1;
			if (!ft_strcmp(argv[i], "-G"))
				g_extended_debug_mode = 1;
		}
	if (g_debug_mode || g_extended_debug_mode)
	{
		if (ioctl(1, TIOCGWINSZ , &info->max) == -1)
			printf("ERROR in ioctl");
		debug_mode(info, DEBUG_START_MODE);
		debug_info_room(info);
	}
}

int			main(int argc, char **argv)
{
	t_link	*link_to_end;
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	get_info(info);
	check_extremity(info);
	debug(argc, argv, info);
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
	(g_debug_mode || g_extended_debug_mode) ? debug_print_path(info) : 0;
	if (info->paths)
		ants_go(info);
	system("leaks lem_in");
	return (0);
}
