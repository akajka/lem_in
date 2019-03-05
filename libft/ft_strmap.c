/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:07:03 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/27 17:05:26 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	c = (char *)malloc((i + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (s[j] != '\0')
	{
		c[j] = f(s[j]);
		j++;
	}
	c[j] = '\0';
	return (c);
}
