/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:29:45 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/27 09:55:50 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <sys/ioctl.h>
# include "debug.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

# define ERROR_START_INIT 0
# define ERROR_END_INIT 1
# define ERROR_COOR_INIT 2
# define ERROR_ANT_INIT 3
# define ERROR_ROOM_NOT_FOUND 4
# define ERROR_REPEAT_ROOM 5
# define ERROR_VALID_LINK 6
# define ERROR_LINK_INIT 7
# define ERROR_REPEAT_COOR 8
# define ERROR_UNCORRECT_NAME_ROOM 9
# define ERROR_PATH_NOT_FOUND 10
# define ERROR_ALLOC_MEMORY 11
# define ERROR_MAP 12

struct				s_room
{
	int				p;
	int				used;
	int				checked;
	int				ant;
	int				x;
	int				y;
	char			*name_room;
	t_link			*links;
	t_room			*next;
};

struct				s_link
{
	t_room			*room;
	t_link			*next;
	t_link			*prev;
};

struct				s_queue
{
	t_link			*link;
	t_queue			*next;
	t_queue			*prev;
};

struct				s_path
{
	int				ness;
	int				room_col;
	int				id;
	t_link			*link;
	t_path			*next;
	t_path			*prev;
};

struct				s_way
{
	t_link			*link;
	t_path			*path;
};

struct				s_step
{
	int				need_step;
	int				show_step;
	int				col_steps;
};

struct				s_info
{
	t_step			*step;
	struct ttysize	max;
	long int		ants;
	int				us;
	int				fast_end;
	int				sum_start_link;
	int				done;
	int				leaks;
	int				col_path;
	int				col_room;
	int				string;
	t_list			*file;
	t_list			*line;
	t_room			*start;
	t_room			*end;
	t_room			*room;
	t_way			*ant_during_way;
	t_path			*paths;
	t_path			*start_path;
};

void				print_error(int error, int string);
void				get_info(t_info *info);
void				get_rooms(t_info *info);
void				get_link(t_info *info, char **sp, int string);
void				info_room(t_info *info, char **s);
void				info_link(t_info *info);
void				save_file(t_info *info, char **s);
void				print_file(t_list *file);
void				check_extremity(t_info *info);
int					bfs(t_info *info);
void				new_way(t_link *last, t_info *info, t_queue *del);
void				ants_go(t_info *info);
t_room				*new_room(t_info *info, char **line);
void				val_test_room(t_room *rooms, t_room *tmp, int string);
void				val_test_link(t_room *room_link,
		t_room *need_room, int string);
void				new_link(t_room *rooms, t_room *need_room,
		char *name_link, int string);
void				get_extremity(t_info *info);
void				ness_use_path(t_info *info);
void				fast_end(t_info *info);
t_queue				*init_queue(t_info *info);

#endif
