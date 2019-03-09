/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:19:57 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/06 18:07:52 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_error(char c, int string)
{
	int				count;
	const char		*val_test;
	const char		*error[11] =
	{"Error during initialization start.",
		"Error during initialization end.",
		"Error during initialization coordinates.",
		"🐜 Error during initialization ants.🐜", "Unknow room error.",
		"Repeat of name room.", "Not valid link.",
		"Error during initialization link.",
		"Repeat of coorditanates.",
		"Unccorect name room.",
		"Map.. 🖕🏿"};

	val_test = "secandlLZ!R";
	count = -1;
	ft_putstr_fd("\033[1;31m‼️ ERROR:", 2);
	ft_putnbr_fd(string, 2);
	ft_putstr_fd("\n\033[0m", 2);
	while (val_test[++count])
		if (c == val_test[count])
			ft_putstr_fd(error[count], 2);
	ft_putstr_fd("\n\033[0m", 2);
	exit(-1);
}
