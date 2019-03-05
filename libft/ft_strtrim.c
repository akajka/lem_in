/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:52:52 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/02 13:06:17 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char			*ft_strtrim(char const *s)
{
	size_t		j;
	size_t		i;
	size_t		k;
	int			len;
	char		*c;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while ((s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v') ||
			(s[i] == ' ') || (s[i] == '\f') || (s[i] == '\r'))
		i++;
	while ((s[j - 1] == '\n') || (s[j - 1] == '\t') || (s[j - 1] == '\v') ||
			(s[j - 1] == ' ') || (s[j - 1] == '\f') || (s[j - 1] == '\r'))
		j--;
	len = j - i;
	if (len < 0)
		len = 0;
	if (!(c = ft_strsub((char *)s, i, len)))
		return (NULL);
	return (c);
}
