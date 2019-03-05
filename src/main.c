/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:37 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/05 15:32:32 by akorobov         ###   ########.fr       */
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

void		iniz(t_info *info)
{
	info->ants = 0;
	info->room = NULL;
	info->start = NULL;
	info->file = NULL;
	info->end = NULL;
	info->path = NULL;
}

int			main(void)
{
	t_info	info;
	int		string;

	iniz(&info);
	string = 0;
	get_info(&info);
	check_extremity(&info);
//	find_paths(&info);
	return (0);
}
