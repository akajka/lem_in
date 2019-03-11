/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go_to_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:39:26 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/11 14:21:53 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant_go_to_the_next_room_in_this_way(t_info *info,
		t_path *path, int ant)
{
	t_link	*link;

	link = path->link;
	link->room->ant = ant;
	while (link->next && link->room->ant)
		link = link->next;
	while ((link = link->prev))
	{
		if (link->next)
			link->next->room->ant = link->room->ant;
		printf("L%d-%s ", link->room->ant, link->room->name_room);
	}
	return (info->done);
}

int			*init_len(t_info *info)
{
	int		*ret;
	int		count;
	t_path	*path;

	count = 0;
	ret = (int *)malloc(sizeof(int) * info->col_path);
	path = info->start_path;
	while (path)
	{
		if (path->valid)
			ret[count++] = path->room_col;
		path = path->prev;
	}
	return (ret);
}

void		ness_use_path(t_info *info)
{
	int		i;
	int		j;
	int		*len;
	t_path	*path;

	len = init_len(info);
	path = info->start_path;
	i = 0;
	while (path)
	{
		j = -1;
		if (path->valid && i)
		{
			while (++j != i)
				path->ness += len[i] - len[j];
			i++;
		}
		path = path->prev;
	}
	free(len);
}

void		ants_go_to_end(t_info *info)
{
	int		ant;
	int		counter;
	t_path	*path;

	ant = 0;
	counter = 0;
	ness_use_path(info);
	while (info->done != info->ants)
	{
		path = info->start_path;
		while (path)
		{
			if (path->valid && ++ant)
			{
				if (info->ants - ant > path->ness)
					ant_go_to_the_next_room_in_this_way(info, path, ant);
				else
				{
					while (ant_go_to_the_next_room_in_this_way(info, path, 0))
						info->done = 0;
					exit(1);
				}
			}
			path = path->prev;
		}
		printf("\n");
	}
}
