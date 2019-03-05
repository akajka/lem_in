/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:44:18 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/29 18:03:40 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*arr1;

	arr1 = (unsigned char *)arr;
	d = (unsigned char)c;
	i = 0;
	while (n--)
		if (*arr1++ == d)
			return ((void *)--arr1);
	return (NULL);
}
