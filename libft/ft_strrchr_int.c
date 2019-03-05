/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:34:48 by akorobov          #+#    #+#             */
/*   Updated: 2019/02/15 11:14:13 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrchr_int(const char *str, int ch)
{
	int		i;

	i = ft_strlen(str);
	if (ch == '\0')
		return (i);
	while (i-- && str[i])
		if (str[i] == ch)
			return (i);
	return (0);
}
