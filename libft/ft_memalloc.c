/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:23:16 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/09 16:09:28 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*c;

	c = (void *)malloc(size * sizeof(void *));
	if (c == NULL)
		return (NULL);
	ft_bzero(c, size);
	return (c);
}
