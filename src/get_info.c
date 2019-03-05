/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:54:25 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/05 15:24:56 by akorobov         ###   ########.fr       */
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
	link = ft_strsplit(info->line->content, '-');
	while (need_room && ft_strcmp(link[0], need_room->name_room))
		need_room = need_room->next;
	if (need_room && link[1])
		new_link(info->room, need_room, link[1], info->string);
	else
	{
		while (link[count])
			ft_strdel(&link[count++]);
		free(link);
		print_error('n', info->string);
	}
	while (link[count])
		ft_strdel(&link[count++]);
	free(link);
}

void		info_room(t_info *info, char **line)
{
	t_room	*tmp;

	if (!digit_test(line[0]) || !digit_test(line[1]) || !digit_test(line[2]))
		print_error('c', info->string);
	tmp = new_room(info, line);
	val_test_room(info->room, tmp, info->string);
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
				break ;
			info_room(info, split);
			while (split[count])
				ft_strdel(&split[count++]);
			free(split);
		}
		info->line = info->line->next;
	}
}

void		get_links(t_info *info)
{
	while (info->line && ++info->string)
	{
		if (info->line->content[0] != '#')
			info_link(info);
		info->line = info->line->next;
	}
}

void		get_info(t_info *info)
{
	char	*line;

	info->string = 1;
	while (get_next_line(0, &line))
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
	if (digit_test(info->line->content) && ++info->string)
		info->ants = ft_atoi(info->line->content);
	else
		print_error('a', info->string);
	info->line = info->line->next;
	get_rooms(info);
	get_links(info);
}
