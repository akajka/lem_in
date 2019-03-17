/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:33:15 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/16 19:14:31 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_elem_str(char *elem, int win, int description)
{
	const char	*arr[6][2] = {
		{"\033[1;35m%*s%*s%*s\033[0m\n", "Name room"},
		{"\033[1;34m%*s%*s%*s\033[0m\n", "Link room"},
		{"\033[1;34m%*s%*s%*s\033[0m\n", "Queue item"},
		{"\033[1;34m%*s%*s%*s\033[0m\n", "Path item"},
		{"\033[1;31m%*s%*s%*s\033[0m\n", "Previos room"},
		{"\033[1;34m%*s%*s%*s\033[0m\n", "PATH:"}
	};
	const int	widths[6] = {10, 10, 11, 10, 13, 6};

	printf(arr[description][0], win / 4 + widths[description],
		arr[description][1], win / 4 - (widths[description] - 2),
		"---", win / 4 - 7, elem);
}

void			print_elem_nbr(int data, int win, int description)
{
	const char	*arr[7][2] = {
		{"\033[1;31m%*s %d\033[0m\n", "Lenght:"},
		{"\033[1;31m%*s%d\033[0m\n", "id_"},
		{"\033[1;31m%*s %d\033[0m\n", "Compatible"},
		{"\n\033[1;34m%*s %d\033[0m\n", "Number of rooms"},
		{"\033[1;34m%*s = %d\033[0m\n\n", "The sum of links start"},
		{"\033[35m%*s %d\033[0m\n", "Number of links"},
		{"\033[35m%*s%d\033[0m\n", "Conflict id_"}
	};
	const int	widths[7] = {8, 4, 11, 16, 23, 16, 13};

	printf(arr[description][0], win / 4 + widths[description],
			arr[description][1], data);
}

void			print_info(t_info *info, t_link *link, t_lock *lock, int op)
{
	t_link			*dlink;
	t_lock			*dlock;

	dlink = link;
	dlock = lock;
	while (dlink)
	{
		print_elem_str(dlink->room->name_room,
				info->max.ts_cols, DEBUG_LINK_ROOM);
		dlink = dlink->next;
	}
	while (dlock)
	{
		print_elem_nbr(dlock->path->id,
				info->max.ts_cols, op);
		dlock = dlock->next;
	}
	printf("\n");
}
