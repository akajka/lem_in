/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appending_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:26:17 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/01 10:37:17 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_appending_char(char *str, char c)
{
	char	*str_with_char;

	if (str)
	{
		str_with_char = ft_strnew(ft_strlen(str) + 1);
		str_with_char = ft_strcpy(str_with_char, str);
	}
	else
		str_with_char = ft_strnew(1);
	*(str_with_char + ft_strlen(str_with_char)) = c;
	ft_strdel(&str);
	return (str_with_char);
}
