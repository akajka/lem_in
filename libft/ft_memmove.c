/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:06:04 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/29 13:39:54 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (s < d)
		while ((int)(--n) >= 0)
			*(d + n) = *(s + n);
	else
		while (++i < (int)n)
			*(d + i) = *(s + i);
	return (dest);
}
