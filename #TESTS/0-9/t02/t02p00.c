/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/29 17:05:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#ifndef DEBUG
# define DEBUG 0
#endif

int	test_format_str_without_specifier_return_value(const char *format)
{
	int			ret[2];

	ret[0] = ft_printf(format);
	ret[1] = printf(format);
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	if (test_format_str_without_specifier_return_value("0")
		&& test_format_str_without_specifier_return_value("0123456789")
		&& test_format_str_without_specifier_return_value(
			"012345678901234567890123456789012345678901"))
		return (0);
	return (1);
}
