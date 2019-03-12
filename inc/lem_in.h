/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:29:45 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 22:14:55 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <sys/ioctl.h>

# ifndef DEBUG
#	define DEBUG 0
# endif

# define DEBUG_START_MODE 0
# define DEBUG_INFO_MODE 1
# define DEBUG_QUEUE_MODE 2
# define DEBUG_PATHS_MODE 3

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
# define ERROR_MAP 11



typedef struct		s_room
{
	int				ant;
	int				used;
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
	struct s_link	*prev;
}					t_link;



typedef struct		s_path
{
	int				ness;
	int				valid;
	int				room_col;
	t_link			*link;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;



typedef struct		s_way
{
	t_link			*link;
	t_path			*path;
}					t_way;



typedef struct		s_info
{
	int				col_steps;
	int				done;
	int				us;
	struct ttysize	max;
	int				col_path;
	int				col_room;
	long int		ants;
	t_list			*file;
	t_list			*line;
	int				string;
	t_room			*start;
	t_room			*end;
	t_room			*room;
	t_way			*ant_during_way;
	t_link			*queue;
	t_link			*q;
	t_path			*paths;
	t_path			*start_path;
}					t_info;


void				print_error(int error, int string);


void				get_info(t_info *info);
void				get_rooms(t_info *info);
void				get_link(t_info *info, char **sp, int string);
void				info_room(t_info *info, char **s);
void				info_link(t_info *info);
void				save_file(t_info *info, char **s);
void				print_file(t_list *file);
void				check_extremity(t_info *info);
void				init_start(t_info *info);
t_link				*bfs(t_info *info);
void				new_way(t_link *last, t_info *info);
void				ants_go(t_info *info);
t_room				*new_room(t_info *info, char **line);
void				val_test_room(t_room *rooms, t_room *tmp, int string);
void				val_test_link(t_room *room_link, t_room *need_room, int string);
void				new_link(t_room *rooms, t_room *need_room,
		char *name_link, int string);
void				get_extremity(t_info *info);
void				ness_use_path(t_info *info);


/** Debug **/


void				debug(t_info *info);
void				debug_mode(t_info *info, int mode);
void				debug_info_room(t_info *info);
void				print_queue(t_info *info);
void				debug_print_path(t_info *info);
void				print_name_room(char *name_room,
		int winsize, int description);

#endif
