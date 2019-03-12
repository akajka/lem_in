/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:47:41 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/12 15:42:53 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		save_file(t_info *info, char *str)
{
	t_list	*tmp;
	t_list	*last;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content = ft_strdup(str);
	tmp->next = NULL;
	last = info->file;
	while (last && last->next)
		last = last->next;
	if (last)
		last->next = tmp;
	else
		info->file = tmp;
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
