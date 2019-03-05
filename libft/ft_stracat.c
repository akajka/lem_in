/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stracat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:05:06 by akorobov          #+#    #+#             */
/*   Updated: 2019/02/13 12:09:37 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stracat(char *dest, char *source)
{
	char	tmp[1024];

	ft_strcpy(tmp, source);
	ft_strcat(tmp, dest);
	ft_strclr(dest);
	ft_strcpy(dest, tmp);
}
