/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:47:41 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/13 16:46:59 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		save_file(t_info *info, char **str)
{
	char	*s;
	t_list	*tmp;
	t_list	*last;
	
	if (!(tmp = (t_list *)ft_memalloc(sizeof(t_list))))
		print_error(ERROR_ALLOC_MEMORY, info->string);
	if (info->step && *str)
		if ((s = ft_strstr(*str,"#Here is the number of lines required:")))
				info->step->need_step = ft_atoi(s + 38);
	last = info->file;
	while (last->next)
		last = last->next;
	tmp->content = *str;
	tmp->prev = last;
	tmp->next = NULL;
	last->next = tmp;
}

void		print_file(t_list *file)
{
	t_list	*list;
	int		i;

	list = file;
	i = 0;
	if (!list)
		print_error(ERROR_MAP, 0);
	while (list && ++i)
	{
		ft_putnbr(i);
		write(1, ": ", 2);
		ft_putendl(list->content);
		list = list->next;
	}
	write(1, "\n", 1);
}
