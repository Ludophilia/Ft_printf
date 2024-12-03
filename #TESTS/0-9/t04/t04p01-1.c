/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t03p01-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 16:08:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#ifndef DEBUG
# define DEBUG 0
#endif

int	test_format_str_with_c_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "%c";
	ret = ft_printf(format, 'c');
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_c_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%c%c%c%c";
	ret = ft_printf(format, 'c', 0, '\001', '\x80');
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_c_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "oh%cque%cse%cpasse%ct-il?";
	ret = ft_printf(format, 'c', 0, '\001', '\x80');
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	if (test_format_str_with_c_specifier_return_value_t0()
		&& test_format_str_with_c_specifier_return_value_t1()
		&& test_format_str_with_c_specifier_return_value_t2())
		return (0);
	return (1);
}

