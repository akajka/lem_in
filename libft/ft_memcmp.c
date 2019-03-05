/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:09:51 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/30 11:36:35 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if ((str1 == NULL && str2 == NULL) || n == 0)
		return (0);
	while (str1[i] == str2[i] && n > 1)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (str1[i] - str2[i]);
}
