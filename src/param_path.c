/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:57:50 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 13:58:38 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*init_len(t_info *info)
{
	int		*ret;
	int		count;
	t_path	*path;

	count = 0;
	ret = (int *)malloc(sizeof(int) * info->col_path);
	path = info->start_path;
	while (path)
	{
		if (path->valid)
			ret[count++] = path->room_col;
		path = path->prev;
	}
	return (ret);
}

void		ness_use_path(t_info *info)
{
	int		i;
	int		j;
	int		*len;
	t_path	*path;

	len = init_len(info);
	path = info->start_path;
	i = 0;
	while (path)
	{
		j = -1;
		if (path->valid && i)
		{
			while (++j != i)
				path->ness += len[i] - len[j];
			i++;
		}
		path = path->prev;
	}
	free(len);
}
