/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:19:30 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/01 10:13:39 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if (!(lst->content = (void *)malloc(sizeof(content) * content_size)))
		{
			free(lst);
			return (NULL);
		}
		else
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
	}
	lst->next = NULL;
	return (lst);
}
