/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/29 14:15:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#ifndef DEBUG
# define DEBUG 0
#endif

// #define NB "01-00"
// #define TITLE "Empty string - return values"
// #define OK_STATUS "[OK]"

int	test_empty_str_return_value(void)
{
	int			ret[2];
	const char	*format;

	format = "\0";
	ret[0] = ft_printf(format);
	ret[1] = printf(format);
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	// dprintf(2, "\033[1m"NB"\033[0m\t"TITLE"\t\033[1;32m"OK_STATUS"\033[0m\n");
	return (1);
}

int	main(void)
{
	if (test_empty_str_return_value() == 1)
		return (0);
	return (1);
}
