/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:29:45 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/05 15:45:57 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
#include "libft.h"
#include <stdio.h>

typedef struct		s_room
{
	int				used;
	int				x;
	int				y;
	char			*name_room;
	struct s_link	*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	int				eval;
	t_link			*link;
	struct s_path	*next;
}					t_path;

typedef struct		s_info
{
	int				ants;
	t_list			*file;
	t_list			*line;
	int				string;
	t_room			*start;
	t_room			*end;
	t_room			*room;
	t_path			*path;
}					t_info;

void				get_info(t_info *info);
void				get_rooms(t_info *info);
void				get_link(t_info *info, char **sp, int string);
void				info_room(t_info *info, char **s);
void				info_link(t_info *info);
void				save_file(t_info *info, char *s);
void				print_error(char c, int string);
void				print_file(t_list *file);
void				check_extremity(t_info *info);


t_room				*new_room(t_info *info, char **line);
void				val_test_room(t_room *rooms, t_room *tmp, int string);
void				new_link(t_room *rooms, t_room *need_room,
		char *name_link, int string);
void				get_extremity(t_info *info);

#endif
