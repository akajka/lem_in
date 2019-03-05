/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:33:33 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/05 20:30:36 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char		*ft_strchr(char *str, int ch)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\0' && (char)ch == '\0')
			return (&str[i + 1]);
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
