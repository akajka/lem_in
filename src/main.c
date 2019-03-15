/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:37 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/15 22:41:08 by akorobov         ###   ########.fr       */
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

int			locked_path(t_path *cur, t_path *all_paths, int i)
{
	int		ret;
	t_lock	*lock;
	t_path	*tmp;

	tmp = cur;
	lock = cur->locked;
	ret = cur->sum_not_compatible;
	while (lock)
	{
		lock->path->test = i;
		lock = lock->next;
	}
	printf("ret path - %d\n", ret);
	tmp = all_paths; 
	while (tmp)
	{
		if (tmp->test != i)
		{
			lock = tmp->locked;
			while (lock)
			{
				if (lock->path->test != i)
					lock->path->test = i;
				else
					ret++;
				lock = lock->next;
			}
		}
		tmp = tmp->prev;
	}
	printf("lock path - %d\n", ret);
	return (ret);
}


void		locking(t_path *path, t_path *start_path)
{
	t_lock	*lock;
	t_path	*tmp;

	lock = path->locked;
	while (lock)
	{
		lock->path->valid = 0;
		lock = lock->next;
	}
	tmp = start_path;
	while (tmp)
	{
		if (tmp->valid)
		{
			lock = tmp->locked;
			while (lock)
			{
				lock->path->valid = 0;
				lock = lock->next;
			}
		}
		tmp = tmp->prev;
	}
}

void		sort_path(t_info *info)
{
	int		i;
	int		best_ret;
	int		cur_res;
	t_path	*tmp;
	t_path	*thebestway;

	i = 1;
	tmp = info->start_path;
	thebestway = tmp;
	best_ret = -1;
	while (tmp)
	{
		if ((cur_res = locked_path(tmp, info->start_path, i++)) <= best_ret &&
				|| best_ret == -1)
		{
			best_ret = cur_res;
			thebestway = tmp;
			printf("now is best - result - %d; id - %d\n",best_ret, thebestway->id);
		}
		else
		{
			printf("current - result - %d; id - %d\n", cur_res, tmp->id);	
			printf("now is best - result - %d; id - %d\n",best_ret, thebestway->id);	
		}
		sleep(2);
		tmp = tmp->prev;
	}
	locking(thebestway, info->start_path);
}

void		result(t_info *info)
{
	debug_info_room(info);
	if (!info->fast_end)
	{
		info->paths ? sort_path(info) : print_error(ERROR_PATH_NOT_FOUND,
				info->string);
		DEBUG == 2 ? debug_print_path(info) : 0;
		ants_go(info);
	}
	else
		fast_end(info);
	if (info->step)
	{
		printf("\nAnts - %ld\n", info->ants);
		printf("Need steps - %d\n", info->step->need_step);
		printf("Steps - %d\n", info->step->col_steps);
		printf("Sum paths- %d\n", info->col_path);
		printf("Sum valid paths - %d\n", info->col_val_path);
	}
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
	info->queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	info->queue->link = (t_link *)ft_memalloc(sizeof(t_link));
	info->queue->link->room = info->start;
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
