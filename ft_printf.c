/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/28 22:29:24 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// How should this function work ? Any idea...?
int	ft_printf(const char *format, ...)
{
	// Everything starts with the format string. The format string should 
	// be parsed:

		// * Iterate on every char of format str
			// * Every 'normal' character will be printed on stdout 
			// * When '%' sign is encountered:
				// * Build the logic to map the following characters to 
				// 	a conversion. In any case, the logic is complete if a
				// 	i,d,p,x,X,c,s,u is encountered.
				// * Determine the conversion to use
				// * convert the associated argument
				// * print it on stdout.
				// * No formatting for now.

	// We will start by a simple case, just to start build the skills to
	// write this program:
		// one int argument, %i/%d. From an int (42).

	ft_putstr_fd((char *)format, 1);
	return (0);
}
