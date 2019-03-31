/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:54:25 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/18 12:44:28 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		info_link(t_info *info)
{
	int		count;
	char	**link;
	t_room	*need_room;

	count = 0;
	need_room = info->room;
	if (!ft_strchr(info->line->content, '-') ||
			ft_strchr(ft_strchr(info->line->content, '-') + 1, '-'))
		print_error(ERROR_LINK_INIT, info->string);
	link = ft_strsplit(info->line->content, '-');
	if (!link[0] || !link[1] || link[2])
		print_error(ERROR_LINK_INIT, info->string);
	while (need_room && ft_strcmp(link[0], need_room->name_room))
		need_room = need_room->next;
	if (!(need_room && link[1]))
		print_error(ERROR_ROOM_NOT_FOUND, info->string);
	new_link(info->room, need_room, link[1], info->string);
	++need_room->p;
	val_test_link(need_room, need_room->links->room, info->string);
	new_link(info->room, need_room->links->room, link[0], info->string);
	++need_room->links->room->p;
	free_2d(&link);
}

void		info_room(t_info *info, char **line)
{
	t_room	*tmp;

	if (!digit_test(line[1]) || !digit_test(line[2]))
		print_error(ERROR_COOR_INIT, info->string);
	tmp = new_room(info, line);
	val_test_room(info->room, tmp, info->string);
	info->col_room++;
	info->room = tmp;
}

void		get_rooms(t_info *info)
{
	char	**split;
	int		count;

	while (info->line && ++info->string)
	{
		if (!ft_strcmp("##start", info->line->content) ||
				!ft_strcmp("##end", info->line->content))
			get_extremity(info);
		else if (info->line->content[0] != '#')
		{
			count = 0;
			split = ft_strsplit(info->line->content, ' ');
			if (ft_size2d(split) != 3)
			{
				free_2d(&split);
				ft_strchr(info->line->content, '-') ? 1 :
					print_error(ERROR_UNCORRECT_NAME_ROOM,
							info->string);
				break ;
			}
			info_room(info, split);
			free_2d(&split);
		}
		info->line = info->line->next;
	}
}

void		get_links(t_info *info)
{
	while (info->line)
	{
		if (info->line->content[0] != '#')
			info_link(info);
		info->string++;
		info->line = info->line->next;
	}
}

void		get_info(t_info *info)
{
	char	*line;

	info->string = 0;
	info->file = (t_list *)ft_memalloc(sizeof(t_list));
	if (!get_next_line(0, &info->file->content))
		print_error(ERROR_MAP, 0);
	while (get_next_line(0, &line))
		save_file(info, &line);
	info->line = info->file;
	print_file(info->line);
	while (info->line && info->line->content[0] == '#' &&
			(info->line->content[1] ?
			info->line->content[1] != '#' : 1) && ++info->string)
		info->line = info->line->next;
	if (info->line && ++info->string && digit_test(info->line->content))
		info->ants = ft_atoi(info->line->content);
	if (info->ants <= 0 || info->ants > INT_MAX)
		print_error(ERROR_ANT_INIT, info->string);
	info->line = info->line->next;
	get_rooms(info);
	get_links(info);
}
