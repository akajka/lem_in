/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:06:41 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/16 18:11:25 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "lem_in.h"

# define DEBUG_START_MODE 0
# define DEBUG_INFO_MODE 1
# define DEBUG_QUEUE_MODE 2
# define DEBUG_PATHS_MODE 3

# define DEBUG_NAME_ROOM 0
# define DEBUG_LINK_ROOM 1
# define DEBUG_QUEUE_ITEM 2
# define DEBUG_PATH_ITEM 3
# define DEBUG_PREVIOS_ROOM 4
# define DEBUG_PATH 5

# define DEBUG_LENGTH 0
# define DEBUG_ID 1
# define DEBUG_COMPATIBLE 2
# define DEBUG_NUMBER_OF_ROOMS 3
# define DEBUG_LINKS_START 4
# define DEBUG_NUMBER_OF_LINKS 5
# define DEBUG_ID_CONFLICT 6

typedef struct s_room		t_room;
typedef struct s_link		t_link;
typedef struct s_queue		t_queue;
typedef struct s_lock		t_lock;
typedef struct s_path		t_path;
typedef struct s_way		t_way;
typedef struct s_step		t_step;
typedef struct s_info		t_info;

void				debug(t_info *info);
void				debug_mode(t_info *info, int mode);
void				debug_info_room(t_info *info);
void				debug_print_queue(t_info *info);
void				debug_print_path(t_info *info);
void				print_elem_str(char *data, int win, int description);
void				print_elem_nbr(int data, int win, int description);
void				print_info(t_info *info, t_link *link,
		t_lock *lock, int op);

#endif
