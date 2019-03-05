/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:47:41 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/04 22:37:45 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_file(t_list *file)
{
	t_list	*list;
	int		i;

	list = file;
	i = 0;
	while (list && ++i)
	{
		ft_putnbr(i);
		write(1, ": ", 2);
		ft_putendl(list->content);
		list = list->next;
	}
}
