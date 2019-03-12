/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go_to_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:39:26 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 13:10:39 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_go_to_the_next_room(t_info *info, int ant, t_path *tmp)
{
	int	j;

	j = 0;
	while (j++ > ant)
	{
		if (info->ant_during_way[j].link->next &&
				info->ant_during_way[j].path == tmp)
		{
			info->ant_during_way[j].link =
				info->ant_during_way[j].link->next;
			write(1, "L", 1);
			ft_putnbr(j);
			write(1, "-", 1);
			ft_putstr(info->ant_during_way[j].link->room->name_room);	
			write(1, " ", 1);
		}
	}
	info->ant_during_way[ant - 1].path = tmp;
	info->ant_during_way[ant - 1].link = tmp->link;
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(info->ant_during_way[ant - 1].link->room->name_room);
	write(1, " ", 1);
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
	int		j;

	info->done = 0;
	while (!info->done)
	{
		info->done = 0;
		j = -1;
		while (++j < info->ants)
		{
			if (info->ant_during_way[j].link)
			{
				info->ant_during_way[j].link = info->ant_during_way[j].link->next;
				info->done = 1;
				write(1, "L", 1);
				ft_putnbr(j + 1);
				write(1, "-", 1);
				ft_putstr(info->ant_during_way[j].link->room->name_room);	
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}

void		ants_go(t_info *info)
{
	int		ant;
	t_path	*tmp;

	ant = 0;
	ness_use_path(info);
	info->ant_during_way =
		(t_way *)malloc(sizeof(t_way) * info->ants);
	while (!info->done)
	{
		info->done = 1;
		tmp = info->start_path;
		while (tmp && ant < info->ants)
		{
			if (tmp->valid && info->ants - ant > tmp->ness && ++ant)
			{
				info->done = 0;
				ant_go_to_the_next_room(info, ant, tmp);
			}
			tmp = tmp->prev;
		}
	}
	ants_go_to_end(info);
}
