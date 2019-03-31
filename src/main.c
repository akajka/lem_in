/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:37 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/27 09:53:21 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_flag(int argc, char **argv, t_info *info)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	if (argc >= 2)
		while (argv[++i])
		{
			if (!ft_strcmp(argv[i], "--stat") || !ft_strcmp(argv[i], "-s"))
				s = 1;
			else if (!ft_strcmp(argv[i], "--leaks") ||
					!ft_strcmp(argv[i], "-l"))
				info->leaks = 1;
			else if (!ft_strcmp(argv[i], "--help"))
			{
				printf("usage: lem_in\n\tcheck leaks:\n\t\t--leaks or -l\n");
				printf("\tcheck statistic:\n\t\t--stat or -s\nTo enable ");
				printf("debug, you need to compile with the required ");
				printf("mode.\nExample:\n\t\"make re DEBUG_MODE=1\"\n");
				printf("The second mode allows you ");
				printf("to see the operation of the algorithm.\n");
				exit(EXIT_SUCCESS);
			}
		}
	s ? info->step = (t_step *)ft_memalloc(sizeof(t_step)) : 0;
}

void		check_extremity(t_info *info)
{
	t_link	*check;

	if (!info->start || !info->start->links)
		print_error(ERROR_START_INIT, info->string);
	if (!info->end || !info->end->links)
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
	DEBUG == 2 ? debug_info_room(info) : 0;
	DEBUG == 2 ? sleep(2) : 0;
}

void		result(t_info *info)
{
	DEBUG ? debug_info_room(info) : 0;
	DEBUG == 2 ? sleep(2) : 0;
	if (!info->fast_end)
	{
		while (++info->us && bfs(info))
			continue ;
		DEBUG ? debug_print_path(info) : 0;
		info->paths ? ants_go(info) : print_error(ERROR_PATH_NOT_FOUND,
				info->string);
	}
	else
		fast_end(info);
	if (info->step)
	{
		printf("\nAnts - %ld\n", info->ants);
		printf("Need steps - %d\n", info->step->need_step);
		printf("Steps - %d\n", info->step->col_steps);
		printf("Sum paths- %d\n", info->col_path);
	}
}

int			main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	get_flag(argc, argv, info);
	get_info(info);
	check_extremity(info);
	DEBUG ? debug(info) : 0;
	result(info);
	info->leaks ? system("leaks -q lem-in") : 0;
	return (0);
}
