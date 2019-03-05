/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:05:12 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/11 13:44:45 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_size(int nb, int i)
{
	if (nb < 0)
		i++;
	while (nb > 9 || nb < -9)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_fill_neg(char *p, int n, int len)
{
	if (n < 0)
		n = -n;
	p[0] = '-';
	while (len-- > 1)
	{
		p[len] = n % 10 + '0';
		n = n / 10;
	}
	return (p);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*p;

	len = ft_size(n, 0);
	if (n > 2147483647)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p[len] = '\0';
	if (n < 0)
		p = ft_fill_neg(p, n, len);
	else
	{
		while (len--)
		{
			p[len] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (p);
}
