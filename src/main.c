/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:37 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/14 21:52:17 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_flag(int argc, char **argv, t_info *info)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	if (argc == 2)
		while (argv[i])
			if (ft_strcmp(argv[i++], "-s"))
				s = 1;
	if (s)
		info->step = (t_step *)ft_memalloc(sizeof(t_step));
}

void		check_extremity(t_info *info)
{
	t_link	*check;
	
	if (!info->start || !info->start->links)
		print_error(ERROR_START_INIT, info->string);
	if (!info->end)
		print_error(ERROR_END_INIT, info->string);
	check = info->start->links;
	while (check)
	{
		if (check->room == info->end)
			info->fast_end = 1;
		info->sum_start_link++;
		check = check->next;
	}
}

void		debug(t_info *info)
{
	if (ioctl(1, TIOCGWINSZ, &info->max) == -1)
		printf("ERROR in ioctl");
	debug_mode(info, DEBUG_START_MODE);
	debug_info_room(info);
}

void		sort_path(t_info *info)
{
	t_path	*tmp;
	t_path	*thebestway;
	t_lock	*lock;

	tmp = info->paths;
	thebestway = info->paths;
	while (tmp)
	{
		if (tmp->sum_not_compatible < thebestway->sum_not_compatible)
			thebestway = tmp;
		tmp = tmp->next;
	}
	lock = thebestway->locked;
	while (lock)
	{
		lock->path->valid = 0;
		lock = lock->next;
	}
}

void		result(t_info *info)
{
	if (!info->fast_end)
	{
		info->paths ? sort_path(info) : print_error(ERROR_PATH_NOT_FOUND,
				info->string);
		ants_go(info);
	}
	else
		fast_end(info);
	if (info->step)
		printf("\nAnts - %ld\nNeed steps - %d\nSteps - %d\n",
				info->ants, info->step->need_step, info->step->col_steps);
}

int			main(int argc, char **argv)
{
	t_link	*link_to_end;
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	get_flag(argc, argv, info);
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
		info->queue = info->queue->next;
	}
	result(info);
	return (0);
}
