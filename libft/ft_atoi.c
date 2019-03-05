/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:00:14 by akorobov          #+#    #+#             */
/*   Updated: 2019/01/31 17:15:21 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int							ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	n;
	int						ng;

	n = 0;
	ng = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		ng = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n *= 10;
		n += (int)str[i] - '0';
		i++;
	}
	if (n > 9223372036854775807 && ng == -1)
		return (0);
	else if (n > 9223372036854775807)
		return (-1);
	return (n * ng);
}
