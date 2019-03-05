/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:19:57 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/05 15:24:18 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_error(char c, int string)
{
	int				count;
	const char		*val_test;
	const char		*error[8] =
	{"start error :", "end error :", "coordinates error :", "ants error :",
		"unknow room error :", "repeat of name room :", "link error :"};

	val_test = "secandl";
	count = -1;
	while (val_test[++count])
		if (c == val_test[count])
			ft_putstr_fd(error[count], 2);
	ft_putnbr_fd(string, 2);
	write(2, "\n", 1);
	exit(-1);
}
