/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:42:41 by akorobov          #+#    #+#             */
/*   Updated: 2018/10/27 17:01:38 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < -9 || nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	if (nb < 0)
	{
		if (nb >= -9 && nb <= 9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' - (nb % 10), fd);
	}
	else
		ft_putchar_fd('0' + (nb % 10), fd);
}
