/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:53:54 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/29 13:42:07 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*c;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		c = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = c;
	}
	*alst = NULL;
}
