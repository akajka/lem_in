/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:19:57 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/18 15:43:09 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_error(int error, int string)
{
	const char		*message[13] = {"Error during initialization start.",
	"Error during initialization end.",
	"Error during initialization coordinates.",
	"🐜 Error during initialization ants.🐜", "Unknow room error.",
	"Repeat of name room.", "Not valid link.",
	"Error during initialization link.",
	"Coordinate repetition.",
	"Unccorect name room.",
	"Path not found.",
	"Memory allocation error.",
	"Map.."};

	ft_putstr_fd("\033[1;31mERROR:", 2);
	ft_putnbr_fd(string, 2);
	ft_putstr_fd("\n\033[0m", 2);
	ft_putstr_fd(message[error], 2);
	ft_putstr_fd("\n\033[0m", 2);
	exit(-1);
}
