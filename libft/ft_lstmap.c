/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:49:54 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/30 16:39:05 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ret;
	t_list		*l;

	if (!lst || !f)
		return (NULL);
	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	l = f(lst);
	lst = lst->next;
	ret = l;
	while (lst)
	{
		if (!(l->next = (t_list*)malloc(sizeof(t_list))))
		{
			free(l);
			return (NULL);
		}
		l->next = f(lst);
		l = l->next;
		lst = lst->next;
	}
	return (ret);
}
