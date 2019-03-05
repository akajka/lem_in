/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:34:48 by akorobov          #+#    #+#             */
/*   Updated: 2018/12/02 14:51:24 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	int		i;

	i = ft_strlen(str);
	if (ch == '\0')
		return ((char *)&str[i]);
	while (i-- && str[i])
		if (str[i] == ch)
			return ((char *)&str[i]);
	return (NULL);
}
