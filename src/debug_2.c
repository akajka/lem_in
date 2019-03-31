/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:33:15 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/27 10:16:56 by akorobov         ###   ########.fr       */
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
		{"\033[1;34m%*s\033[0m\n", "PATH:"}
	};
	const int	widths[6] = {10, 10, 11, 10, 13, 6};

	if (description != 5)
		printf(arr[description][0], win / 4 + widths[description],
			arr[description][1], win / 4 - (widths[description] - 2),
			"---", win / 4 - 7, elem);
	else
		printf(arr[description][0], win / 4 + widths[description],
			arr[description][1]);
}

void			print_elem_nbr(int data, int win, int description)
{
	const char	*arr[5][2] = {
		{"\033[1;31m%*s %d\033[0m\n", "Lenght:"},
		{"\033[1;31m%*s%d\033[0m\n", "id_"},
		{"\n\033[1;34m%*s %d\033[0m\n", "Number of rooms"},
		{"\033[1;34m%*s = %d\033[0m\n\n", "The sum of links start"},
		{"\033[35m%*s %d\033[0m\n", "Number of links"},
	};
	const int	widths[5] = {8, 4, 13, 16, 16};

	printf(arr[description][0], win / 4 + widths[description],
			arr[description][1], data);
}

void			print_links(t_info *info, t_link *link)
{
	t_link			*dlink;

	dlink = link;
	while (dlink)
	{
		print_elem_str(dlink->room->name_room,
				info->max.ts_cols, DEBUG_LINK_ROOM);
		dlink = dlink->next;
	}
	printf("\n");
}
