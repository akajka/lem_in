/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:37:10 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/01 10:39:01 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int sol;

	if (nb <= 0)
		return (0);
	sol = 1;
	while (sol * sol < nb)
		sol++;
	if (sol * sol == nb)
		return (sol);
	else
		return (0);
}
