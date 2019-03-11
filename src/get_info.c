/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:54:25 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/11 14:55:40 by akorobov         ###   ########.fr       */
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
	if (!ft_strchr(info->line->content, '-'))
		print_error('L', info->string);
	link = ft_strsplit(info->line->content, '-');
	if (!link[0] || !link[1])
		print_error('!', info->string);
	while (need_room && ft_strcmp(link[0], need_room->name_room))
		need_room = need_room->next;
	if (need_room && link[1])
		new_link(info->room, need_room, link[1], info->string);
	else
	{
		free_2d(&link);
		print_error('n', info->string);
	}
	free_2d(&link);
}

void		info_room(t_info *info, char **line)
{
	t_room	*tmp;

	if (!digit_test(line[1]) || !digit_test(line[2]))
		print_error('c', info->string);
	tmp = new_room(info, line);
	val_test_room(info->room, tmp, info->string);
	info->room = tmp;
}

void		get_rooms(t_info *info)
{
	char	**split;
	int		count;

	while (info->line && ++info->string && ++info->col_room)
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
					print_error('c', info->string);
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
	while (get_next_line(0, &line) && line)
	{
		save_file(info, line);
		free(line);
	}
	print_file(info->file);
	info->line = info->file;
	while (info->line && info->line->content[0] == '#' &&
			(info->line->content[1] ?
			info->line->content[1] != '#' : 1) && ++info->string)
		info->line = info->line->next;
	if (info->line && ++info->string && digit_test(info->line->content))
		info->ants = ft_atoi(info->line->content);
	if (info->ants <= 0 || info->ants > 22147483647)
		print_error('a', info->string);
	info->line = info->line->next;
	get_rooms(info);
	get_links(info);
}
