/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:33:43 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/27 17:06:48 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*c;

	c = (char *)malloc(((int)size + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	ft_bzero(c, ((int)size + 1));
	return (c);
}
