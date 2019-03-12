/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go_to_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:39:26 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 17:41:37 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_step(t_way ant, int ant_nbr)
{
	write(1, "L", 1);
	ft_putnbr(ant_nbr);
	write(1, "-", 1);
	ft_putstr(ant.link->room->name_room);
	write(1, " ", 1);
}

void	ant_go_to_the_next_room(t_info *info, int ant)
{
	while (--ant >= 0)
	{
		if (info->ant_during_way[ant].link->next)
		{
			info->done = 0;
			info->ant_during_way[ant].link = info->ant_during_way[ant].link->next;
			print_step(info->ant_during_way[ant], ant + 1);
		}
	}
}

void		ants_go(t_info *info)
{
	int		ant;
	t_path	*tmp;

	ant = 0;
	ness_use_path(info);
	info->ant_during_way = (t_way *)ft_memalloc(sizeof(t_way) * info->ants);
	while (!info->done)
	{
		info->done = 1;
		tmp = info->start_path;
		ant ? ant_go_to_the_next_room(info, ant) : 0;
		while (tmp)
		{
			if (tmp->valid && info->ants - ant > tmp->ness)
			{
				info->done = 0;
				info->ant_during_way[ant].path = tmp;
				info->ant_during_way[ant].link = tmp->link;
				print_step(info->ant_during_way[ant], ant + 1);
				ant++;
			}
			tmp = tmp->prev;
		}
		write(1, "\n", 1);
	}
}
