/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:29:45 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/09 23:02:15 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
#define DEBUG_START_MODE 0
#define DEBUG_INFO_MODE 1
#define DEBUG_QUEUE_MODE 2
#define DEBUG_PATHS_MODE 3
#include "libft.h"
#include <stdio.h>
#include <sys/ioctl.h>

typedef struct		s_room
{
	int				ant;
	int				checked;
	int				x;
	int				y;
	char			*name_room;
	struct s_link	*links;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	int				valid;
	int				room_col;
	t_link			*link;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_info
{
	int				us;
	struct ttysize	max;
	int				col_room;
	long int		ants;
	t_list			*file;
	t_list			*line;
	int				string;
	t_room			*start;
	t_room			*end;
	t_room			*room;
	t_link			*queue;
	t_link			*q;
	t_path			*paths;
	t_path			*start_path;
}					t_info;

int					g_g;
void				get_info(t_info *info);
void				get_rooms(t_info *info);
void				get_link(t_info *info, char **sp, int string);
void				info_room(t_info *info, char **s);
void				info_link(t_info *info);
void				save_file(t_info *info, char *s);
void				print_error(char c, int string);
void				print_file(t_list *file);
void				check_extremity(t_info *info);
void				init_start(t_info *info);
t_link				*bfs(t_info *info);
void				new_way(t_link *last, t_info *info);


t_room				*new_room(t_info *info, char **line);
void				val_test_room(t_room *rooms, t_room *tmp, int string);
void				new_link(t_room *rooms, t_room *need_room,
		char *name_link, int string);
void				get_extremity(t_info *info);

void				debug(int argc, char **argv, t_info *info);
void				debug_mode(t_info *info, int mode);
void				debug_info_room(t_info *info);
void				print_queue(t_info *info);
void				debug_print_path(t_info *info);
void				print_name_room(char *name_room,
		int winsize, int description);

#endif
