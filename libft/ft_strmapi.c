/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:13:05 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/27 17:05:37 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		c[j] = f(j, s[j]);
		j++;
	}
	c[j] = '\0';
	return (c);
}
